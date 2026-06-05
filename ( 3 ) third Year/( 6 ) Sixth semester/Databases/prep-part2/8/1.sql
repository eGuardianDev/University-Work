
-- 1.1
use movies

select * from MOVIESTAR

insert MOVIESTAR values (
    'Nicole Kidman', NULL, 'F', 20-06-1967
)

-- 1.2

select * from MOVIEEXEC

delete from MOVIEEXEC
where NETWORTH <= 10000000;

insert into MOVIEEXEC(Cert#, Name,ADDRESS,NETWORTH) VALUES ( 699, 'Peter', Null, 100)

-- 1.3

select * from MOVIESTAR

delete from MOVIESTAR
where Address is null

-- 1.4

BEGIN TRANSACTION
select * from MOVIEEXEC
select * from STUDIO

update MOVIEEXEC
set NAME = 'Pres. ' + NAME
where MOVIEEXEC.CERT# in(
    select presc# from STUDIO
)

ROLLBACK TRANSACTION
-- 2.1
use pc

-- !

BEGIN TRANSACTION
select * from pc
where model = 1100;
select * from product
where model = 1100;
insert into product values ('C', 1100, 'PC')

insert into pc(code, model, speed, ram, hd, cd, price) values (12, 1100,2400,2048,500,'52x',299)


select * from pc
where model = 1100;
select * from product
where model = 1100;

ROLLBACK TRANSACTION

-- 2.2

delete from product 
where model = 1100;

delete from pc
where model = 1100;


-- 2.3

select * from pc
select * from laptop

BEGIN TRANSACTION


insert into laptop (code, model, speed, ram, hd, price, screen)
select
    pc.code + 6,
    pc.model + 100,
    pc.speed,
    pc.ram,
    pc.hd,
    pc.price + 500,
    15
from pc  

select * from laptop
ROLLBACK TRANSACTION;

-- 2.4

BEGIN TRANSACTION

select * from laptop;

delete from laptop 
where laptop.model in (
select model from product
where  product.[type] = 'Laptop' and 
    maker in 
(
select maker from product
group by maker
except
select maker from product
where type = 'Printer'
group by maker
))

select * from laptop;

ROLLBACK TRANSACTION;

-- 2.5

BEGIN TRANSACTION

select * from product

update product
set product.maker =  'A'
where product.maker = 'B'

select * from product

ROLLBACK TRANSACTION;


-- 2.6

-- ! 

BEGIN TRANSACTION

select * from pc
update pc
set 
    pc.price = pc.price/2,
    pc.hd = pc.hd + 20;

select * from pc
ROLLBACK TRANSACTION;


-- 2.7

BEGIN TRANSACTION

select * from laptop

update laptop 
set
    laptop.screen +=1
where laptop.model in
(
select model from product
where product.maker = 'B'
)
select * from laptop


ROLLBACK TRANSACTION;



-- 3.1
use ships

BEGIN TRANSACTION

select * from ships
select * from classes

insert into classes(class, [Type], country, numguns, bore, displacement)
values  ('Nelson', 'bb', 'Gt.Britain', 9, 16, 34000),
        ('Rodney', 'bb', 'Gt.Britain', 9, 16, 34000) 

insert into ships(name,class,LAUNCHED)
values  ('Nelson', 'Nelson', 1927),
        ('Rodney1', 'Rodney', 1927)

select * from ships
select * from classes

rollback TRANSACTION;

-- 3.2

BEGIN TRANSACTION


select * from ships

delete from ships
where ships.NAME in 
(select ship from OUTCOMES
where RESULT = 'sunk')

delete from OUTCOMES
where outcomes.SHIP in 
(select ship from OUTCOMES
where RESULT = 'sunk')


select * from ships

rollback TRANSACTION;



-- 3.3
BEGIN TRANSACTION

select * from classes

update classes 
set 
    bore = bore * 2.54,
    displacement = displacement * 1.1;

select * from classes

rollback TRANSACTION;

-- 3.4

BEGIN TRANSACTION

delete outcomes 
where OUTCOMES.SHIP in (
    select ship 
    from ships
    where ships.CLASS in ( 
        select ships.CLASS from ships
        group by ships.CLASS
        having count(*) <= 3
    )
)

delete ships 
where ships.CLASS in (
    select ships.CLASS from ships
    group by ships.CLASS
    having count(*) <= 3
)

delete classes
where classes.CLASS in (
    select class from CLASSES
    where classes.CLASS in (
        select ships.CLASS from ships
        group by ships.CLASS
        having count(*) < 3
    )
)
rollback TRANSACTION;

-- 3.5

BEGIN TRANSACTION

select * from CLASSES

update classes
set 
    NUMGUNS = (select NUMGUNS from classes
    where CLASS = 'Bismarck'),
    DISPLACEMENT = (select  DISPLACEMENT from classes
    where CLASS = 'Bismarck')
where classes.CLASS = 'Iowa'

select * from CLASSES

ROLLBACK TRANSACTION