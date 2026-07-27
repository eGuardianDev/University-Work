
-- 1.1

use movies;
go

create view v_birthdays_females
as
    select moviestar.NAME, MOVIESTAR.BIRTHDATE
    from MOVIESTAR
    where MOVIESTAR.GENDER = 'F';
go


-- 1.2

create view v_actor_movies_count
AS

    select MOVIESTAR.NAME, count(STARSIN.MOVIETITLE) as 'Movies_in'
    from MOVIESTAR
    left outer join STARSIN on STARSIN.STARNAME = MOVIESTAR.NAME
    group by MOVIESTAR.NAME
GO


-- 1.3
-- за 1.1 може и да може, ама това where би го спряло
-- With check options will allow us to block bad ones, Update and delete work
-- за 1.2 не защото имаме join
-- YES



-- 2.1
use pc
go

create view v_all_product
as 
    select code, model, price from pc
    union ALL
    select code, model, price from laptop
    union ALL
    select code, model, price from printer
GO


-- 2.2
alter view v_all_product
as 
    select code, model, price, 'pc' as 'type' from pc
    union ALL
    select code, model, price, 'laptop' as 'type' from laptop
    union ALL
    select code, model, price, 'printer' as 'type' from printer
GO

-- 2.3
alter view v_all_product
as 
    select code, model, price, speed, 'pc' as 'type' from pc
    union ALL 
    select code, model, price, speed, 'laptop' as 'type' from laptop
    union ALL
    select code, model, price, null as 'speed', 'printer' as 'type' from printer
GO



-- 3.1

use ships
go


create view BritishShips
as
    select ships.CLASS, classes.[TYPE], classes.NUMGUNS, classes.BORE, classes.DISPLACEMENT, ships.LAUNCHED
    from ships
    left outer join classes on classes.CLASS = ships.CLASS
    where classes.COUNTRY = 'Gt.Britain' --!
go


-- 3.2

select NUMGUNS, DISPLACEMENT from BritishShips bs
where bs.[TYPE] = 'bb' and bs.LAUNCHED < 1919 -- !


-- 3.3

select NUMGUNS, DISPLACEMENT
from ships
left outer join classes on classes.CLASS = ships.CLASS
where classes.[TYPE] = 'bb' and ships.LAUNCHED < 1919 -- !


-- 3.4

select country, max(DISPLACEMENT) from CLASSES
group by country
go

-- 3.5


create view v_sinked 
as 
    select ships.NAME from ships
    left outer join OUTCOMES on OUTCOMES.SHIP = ships.NAME
    where OUTCOMES.RESULT = 'sunk'
go

-- 3.6

ALTER TABLE OUTCOMES
ADD DEFAULT 'sunk' FOR RESULT;;

Insert into OUTCOMES
values
    ('California','Guadalcanal', default)
go

-- select * from OUTCOMES
-- where OUTCOMES.SHIP = 'California'

select * from v_sinked
go

-- 3.7
create or alter view v_weapons
as 
    select classes.CLASS, NUMGUNS from classes
    where classes.NUMGUNS >= 9
with check OPTION
go

select * from v_weapons;
go

update v_weapons
set 
   NUMGUNS = 5 
where v_weapons.class = 'Iowa'
go


-- 3.8
create or alter view v_weapons
as 
    select classes.CLASS, NUMGUNS from classes
    where classes.NUMGUNS >= 9
go


-- 3.9

create or alter view special_battles
as 
    select battles.NAME from BATTLES
    left outer join OUTCOMES on OUTCOMES.BATTLE = BATTLES.NAME
    left join ships on ships.NAME = outcomes.SHIP
    left join classes on classes.CLASS = ships.CLASS
    where classes.NUMGUNS  < 9
    group by battles.NAME
    having sum(case when outcomes.RESULT = 'damaged' then 1 else 0 end) > 0
        and count(ships.NAME) >= 3
go

select * from special_battles

select * from BATTLES
    left outer join OUTCOMES on OUTCOMES.BATTLE = BATTLES.NAME
    left join ships on ships.NAME = outcomes.SHIP
    left join classes on classes.CLASS = ships.CLASS
