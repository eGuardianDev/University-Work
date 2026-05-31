

create or alter view USShipsDetails
as 
select s.name, s.class, c.type, c.numguns, c.bore, c.displacement, s.LAUNCHED
from classes c
    join ships s on c.class = s.class 
where c.country = 'USA'
with check option 
go


alter view USShipsDetails
as 
select s.name, s.class, c.type, c.numguns, c.bore, c.displacement, s.LAUNCHED
from classes c 
    join ships s on c.class = s.class 
where c.country = 'USA'
GO

-- drop view USShipsDetails
-- Go


update USShipsDetails
set  
    displacement = 10000
where name = 'California'



select * from USShipsDetails


-- trigger

DECLARE @numGuns int = 10;

Declare @country varchar(32);
set @country = 'Germany';

Set @numGuns +=1;

Declare @t Table (id int, name varchar(32));
Insert into @t values(1, 'a');
-- Select * from @t;

if @numGuns > 10
BEGIN 
    PRINT 'Big guns';
END
Else 
begin
    print 'Small guns';
end


While @numGuns < 20 
BEGIN
    PRINT @numGuns
    Set @numGuns +=1
END 
GO


-- If exists (subquery)
-- BEGIN 
--     ....
-- END

-- RETURN;

-- RAISERROR('ERROR MESSAGE', 16, 10);

CREATE OR ALTER TRIGGER TR_SHIP_1 on ships
instead of insert
AS
INSERT INTO SHIPS 
    SELECT 
        NAME,
        CLASS,
        CASE 
            WHEN LAUNCHED > YEAR(GETDATE()) THEN NULL 
            ELSE LAUNCHED
        END AS LAUNCHED
    from inserted
GO

select * from ships 

insert into ships values 
    ('TSHIP1', 'Yamato',5000),
    ('TSHIP2', 'Yamato',1941);
go

select * from ships where name like 'TSHIP%'
go



CREATE OR ALTER TRIGGER TR_SHIP_2 on ships 
after delete 
as 
    delete from CLASSES 
    WHERE CLASS IN (SELECT CLASS FROM deleted)
        and class not in (Select class from ships )
go

select class, count(*) from ships group by class
select * from ships 
delete from ships where name = 'Class A'

Select * from classes
go

-- SHIPS: FOREIGN KEY (CLASS) REFERENCES CLASSES(class) ON DELETE CASCADE
