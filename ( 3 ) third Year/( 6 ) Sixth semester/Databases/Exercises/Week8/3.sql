
use mods


With PricesCTE (model, price) as (
    Select model, price from pc
    UNION
    Select model, price from laptop 
    UNION
    select model, price from printer
)
select * 
from pricesCTE 
where price = (select max(price) from pricesCTE);




With PricesCTE (model, price) as (
    Select model, price from pc
    UNION
    Select model, price from laptop 
    UNION
    select model, price from printer
),
MaxpriceCTE (price) as 
(
    select max(price) from PricesCTE
)
select * from PricesCTE 
where price = (select max(price) from PricesCTE)




With PricesCTE (model, price) as (
    Select model, price from pc
    UNION
    Select model, price from laptop 
    UNION
    select model, price from printer
),
MaxpriceCTE (price) as 
(
    select max(price) from PricesCTE
)
select * from PricesCTE 
where price = (select max(price) from PricesCTE)




use nw

select employeeId, firstname, lastname, title, reportsto from employees




with EmployeesHierarchyCTE AS
(
    Select EmployeeID, LastName, NULL AS BossLastName, 0 as Depth  from employees where ReportsTo is NULL
    union all 
    select e.employeeId, e.LastName, r.EmployeeID, r.LastName, r.Depth + 1 as Depth 
    from EmployeesHierarchyCTE r  
        Join employees e on e.ReportsTo = r.employeeId
)
Select * from EmployeesHierarchyCTE



-- with EmployeesHierarchyCTE as 
-- (
--     select 
--         employeeID,
--         lastname,
--         cast(NUll as int) as BossId,
--         cast(Null as varchar(max)) as BossLastName 
--         0 as Depth from Employees 
--     where ReportsTo is NULL
--     union all 
--     select
--         e.employeeId,
--         e.lastname,
--         r.employeeId,
--         cast(r.lastname as varchar(max)),
--         r.depth+1 as depth 
-- )



use mods

select * from classes

INSERT INTO Classes (CLASS, TYPE, country, numguns, bore, DISPLACEMENT)
    values ('class X', 'bb', 'Germany', 10,10,100000)


INSERT INTO Classes
    values ('class X', 'bb', 'Germany', 10,10,100000)


INSERT INTO Classes (DISPLACEMENT,CLASS, TYPE, country, numguns, bore)
    values (100000,'class X', 'bb', 'Germany', 10,10)




insert into classes (class, type, country)
    values ('Class A', 'bb', 'USA')

insert into classes (class, type, country)
    values ('Class A', 'bb', 'USA')




INSERT INTO Classes (DISPLACEMENT,CLASS, TYPE, country, numguns, bore)
    values (100000,'class X', 'bb', 'Germany', 10,10),
     (100000,'class X', 'bb', 'Germany', 10,10),
      (100000,'class X', 'bb', 'Germany', 10,10)




select * from classes
-- за всички класове, за които displacement не е NULL и няма корабите в таблица ships
-- да се сздаде нов кораб с име съвпадащо с името на класа и година на пускане на вода - текуща 

INSERT into SHIPS(NAME, CLASS, launched)
    select class as name, class, year(GETDATE()) as launched 
    from classes 
    where class not in (select class from ships)
        and DISPLACEMENT is not null


select * from ships


select class as name, class, year(getdate()) as launched into ships2
from classes 
where DISPLACEMENT is not null


select * from ships2



begin TRANSACTION

    delete from classes where DISPLACEMENT = 100000


    truncate table classes

    select * from classes


ROLLBACK


update pc
set 
    price = price * 3
where ram = 128

select * from pc


use nw

select * from orders
select *from [order details]


update o 
set 
    o.TotalPrice = t.TotalPrice 
FROM orders o 
    join (select orderID, sum(unitPrice* quantity * (1-discount)) as TotalPrice 
        from [Order details]
        group by OrderID) t on o.orderID = t.orderID 


select * from orders