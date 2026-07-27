
use movies

-- 1.1

select * from moviestar;

insert into MOVIESTAR values ('Brus Williams', 'Home', 'M', 1999-05-05);
go;

create or alter trigger t_Movie_World
on movie
After Insert 
as 
    if exists (
        select inserted.TITLE from inserted
        where (inserted.TITLE like '%save%') or (inserted.title like '%world%')) 
    begin
            insert into STARSIN
            select inserted.TITLE, inserted.[YEAR], 'Brus Williams' from inserted
            where (inserted.TITLE like '%save%') or (inserted.title like '%world%')
    end

select * from movie

insert into movie values
('save the world', 1923, 124, 'Y', 'Paramount',555)

select * from STARSIN
where STARSIN.MOVIETITLE like 'save the world'
go



-- -- 1.2

-- create trigger t_under_500_000
-- on movieexec
-- instead of insert
-- as 
-- begin
--     if exists (
--         select NETWORTH from inserted
--         where NETWORTH < 500000
--     )
--     BEGIN 
--         raiserror('Networth is below 500 000', 16, 10)
--         ROLLBACK;
--     end;
--     else 
--         if not exists ( select * from inserted )
--          insert into MOVIEEXEC
--          select * from inserted
--         else 
--          update MOVIEEXEC 
--          set me.NETWORTH = i.NETWORTH
--          from MOVIEEXEC as me
--          join inserted i on me.NAME = i.NAME and me.CERT# = i.CERT#
--     end
-- end


create or alter trigger t_under_500_000
on movieexec
instead of insert 
as 
begin 
    insert into MOVIEEXEC
    select * from inserted 

    if ( select avg(MOVIEEXEC.NETWORTH) from MOVIEEXEC) < 500000
    begin 
        RAISERROR('AVG networth below 500000',16,1);
        ROLLBACK;
    end 
end
go

CREATE or alter TRIGGER t_avg_networth_update
ON MOVIEEXEC
AFTER UPDATE
AS
BEGIN
    IF (SELECT AVG(CAST(NETWORTH AS BIGINT)) FROM MOVIEEXEC) < 500000
    BEGIN
        RAISERROR('AVG networth below 500000',16,1);
        ROLLBACK;
    END
END;

select avg(MOVIEEXEC.NETWORTH) from MOVIEEXEC

select * from MOVIEEXEC

update MOVIEEXEC
set NETWORTH = 1000000
where cert# = 222
go

-- 1.3

create or alter trigger t_remove_producer
on movieexec
instead of delete
as 
begin 
    update movie
    set PRODUCERC#  = null 
    where movie.PRODUCERC# in (select deleted.CERT# from deleted)
    -- delete from movie 
    -- where PRODUCERC# = deleted.CERT#
    delete from MOVIEEXEC
    where MOVIEEXEC.CERT# in (select deleted.CERT# from deleted)
end
go



-- 1.4
create trigger t_insert_starsin
on starsin
instead of update 
as 
begin

    insert into movie
    select inserted.MOVIETITLE, inserted.MOVIEYEAR, null, null, null, null from inserted
    where not exists(
        select 1
        from movie 
        where inserted.MOVIETITLE = movie.title and inserted.MOVIEYEAR = movie.[YEAR])


    insert into MOVIESTAR
    select inserted.starname, null, null, null from inserted 
    where not exists( select 1 from moviestar 
    where inserted.STARNAME = MOVIESTAR.NAME)
    

    INSERT INTO STARSIN (MOVIETITLE, MOVIEYEAR, STARNAME)
    SELECT MOVIETITLE, MOVIEYEAR, STARNAME
    FROM inserted;
end
go



-- 2.1

use pc
go

create or alter trigger t_delete_laptop_from_d
on laptop 
after delete 
as 

    insert into pc (code, model, speed, ram, hd, cd, price)
    select code+100, 1121,speed,ram,hd, '52x' ,price from deleted
    left join product on product.model = deleted.model
    where maker = 'D'



select * from pc
select * from laptop
go

drop trigger t_delete_laptop_from_d
go
-- 2.2

create or alter trigger t_cpu_speed_less 
on pc 
instead of update 
as 
    if
        (select min(pc.speed) from pc
                where pc.model not in (select inserted.model from inserted))
        > (select min(inserted.speed) from inserted)
        begin 
            RAISERROR('Speed below minimum', 16, 1)
            ROLLBACK;
        end 

go

drop trigger t_cpu_speed_less
go
-- 2.3

create or alter trigger t_pc_maker_no_printers
on product 
instead of insert, update 
as 

    if exists 
    (
        select maker from product
        union 
        select maker from inserted
        where inserted.[type] = 'printer' and inserted.[type] = 'pc'
        group by maker
    )
    begin
        RAISERROR('Pc makers cannot maker printers', 16, 1) 
        ROLLBACK;
    end
    else 

    insert into product 
    select * from inserted

    delete from product 
    select * from deleted

go 

drop trigger t_pc_maker_no_printers
go


-- 2.4

create trigger t_maker_pc_and_laptop
on product
instead of insert, update
as 
    

go


-- 2.5

create or alter trigger t_average_laptop_price
on laptop 
instead of update
as 
begin

    update l
    set l.model = i.model, l.hd = i.hd, l.price = i.price, l.ram = i.ram, 
        l.screen = i.screen, l.speed = i.speed
    from laptop l
    join inserted i on l.code = i.code
    
    if exists ( select product.maker from laptop
    left join product on product.model = laptop.model
    group by maker 
    having avg(laptop.price) < 2000)    
        RAISERROR('Some producers make below on average < 2000',16,1);
        ROLLBACK
end
go

drop trigger t_average_laptop_price
go
-- 2.6


create or alter trigger t_laptop_mem_more_than_pc
on laptop 
instead of insert, update
as 
begin 

    if exists (select inserted.hd, inserted.price from inserted
    cross join pc 
    where inserted.hd > pc.hd and inserted.price < pc.price)
        RAISERROR('Laptop cannot be cheaper than pc with less memory space', 16, 1)
        ROLLBACK


    if exists (select * from deleted)
        update l
        set l.hd = i.hd, l.model = i.model, l.price = i.price, 
        l.ram = i.ram, l.screen = i.screen, l.speed = i.screen
        from laptop l
        join inserted i on i.code = l.code
    else 
        insert into laptop 
        select * from inserted

end 
go



-- 2.7

select * from printer
go

create trigger t_forbidden_printer
on printer 
instead of insert 
as 
    insert into printer 
    select * from inserted
    where inserted.[type] not like 'Matrix'
go




-- 3.1
use ships
go

create trigger t_bigger_than_35000
on classes 
instead of insert 
as 
    insert into classes 
    select * from inserted 
    where inserted.DISPLACEMENT <= 35000

    insert into classes(class, type, country, NUMGUNS,BORE, DISPLACEMENT)
    select class, type, COUNTRY,NUMGUNS,BORE, 35000 from inserted 
    where inserted.DISPLACEMENT > 35000

go 



-- 3.2

create view classes_and_guns
as
select class, NUMGUNS from classes 
go

create trigger t_class_and_guns_deletion
on classes_and_guns
instead of delete 
as 
  
    delete from classes
    where classes.CLASS in (select deleted.CLASS from deleted)


    delete from ships
    where ships.CLASS in (select deleted.class from deleted)

go



-- 3.3

create or alter trigger t_ships_created 
on ships 
instead of insert, update 
as 
begin 

    if exists (select * from deleted)
        update s 
        set s.LAUNCHED = i.LAUNCHED, s.NAME = i.NAME
        from ships s
        join inserted i on i.CLASS = s.CLASS
    else 
        insert into ships 
        select * from inserted


    if ((select max(val) from ( select count(*) as val from ships group by ships.CLASS ) c )> 2 )
        RAISERROR('Each class cannot have more than 2 ships',16, 1);
        ROLLBACK
end
go




-- 3.4

select * from OUTCOMES
go

create or alter trigger t_unfair_battle
on OUTCOMES
instead of insert, update
as

begin
   
    if exists ( select * from deleted )
        update o 
        set o.result = d.RESULT
        from OUTCOMES o 
        join inserted d on o.SHIP = d.ship and o.BATTLE = d.BATTLE
    else 
        insert into outcomes 
        select * from inserted



    if exists ( 
        select * from ( select o.battle,
        (select count(*) as 'less' from outcomes o1
                left outer join ships on ships.NAME = o1.SHIP
                left outer join classes on classes.CLASS = ships.CLASS
                where o1.BATTLE = o.battle and classes.NUMGUNS < 9) as 'less',
        (select count(*) as 'more' from outcomes o1
                left outer join ships on ships.NAME = o1.SHIP
                left outer join classes on classes.CLASS = ships.CLASS
                where o1.BATTLE = o.battle and classes.NUMGUNS >= 9) as 'more' 
        from outcomes o
        group by battle) f
        where f.less != 0 and f.more !=0
    ) 
        RAISERROR('Cannot have smaller ships in battle with bigger ships', 16,1);
        ROLLBACK
end
go


-- 3.5


create trigger t_after_sunk
on outcomes 
instead of update, insert
as
begin 
    if exists ( select * from deleted )
        update o 
        set o.RESULT = i.result
        from outcomes o  
        join inserted i on i.ship = o.ship and i.battle = o.battle  
    else 
        insert into outcomes 
        select * from inserted


    if exists (select ship from outcomes o1
    left join BATTLES on BATTLES.NAME = o1.BATTLE
    where (battles.[DATE] >
        (select min(battles.[DATE]) from outcomes o 
        left join BATTLES on BATTLES.NAME = o.BATTLE
        where o.RESULT = 'sunk' and o.ship = o1.ship
        group by ship))
    group by ship)

        RAISERROR('Ship cannot be sunk and then go to battle again!', 16,1);
        ROLLBACK


    -- select * from ships
    -- where name = 'California'

    -- select * from outcomes 
    -- left join battles on battles.NAME = outcomes.BATTLE
    -- where ship = 'California'

end
go

-- insert into outcomes 
-- values ('Duke of York', 'Surigao Strait', 'sunk')


-- select * from ships

-- select * from BATTLES