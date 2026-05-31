


use pc
GO

CREATE VIEW Computers 
AS
    select code, 'pc' type, model, speed, ram, price from pc
    UNION
    select code, 'laptop' type, model, speed, ram, price from laptop
GO


CREATE TRIGGER IT_COMPUTERS on Computers 
INSTEAD OF UPDATE 
AS 
    IF UPDATE(code) OR Update(type)
    BEGIN 
        RAISERROR('Code and Type are immutable', 16, 1);
        RETURN;
    END


    UPDATE pc 
    SET 
        model = i.model,
        speed = i.speed,
        ram = i.ram,
        price = i.price
    from pc 
        join inserted i on pc.code = i.code and i.type = 'pc'
    
    UPDATE laptop
    SET 
        model = i.model,
        speed = i.speed,
        ram = i.ram,
        price = i.price
    from pc 
        join inserted i on pc.code = i.code and i.type = 'laptop'

GO


-- ако има UNION, update няма да работи, освен ако няма trigger

select * from Computers
go
update Computers Set price = 100 where code = 1 and type ='pc'
Go

-- всеки производител на компютър трябва да произвежда лаптоп със същата или по-висока честота на процесора


-- TABLE PC 
--  INSERT, UPDATE

-- TABLE laptop
--  UPDATE, DELET


CREATE TRIGGER T_AIU_PC ON pc
AFTER INSERT, UPDATE 
AS 
    SELECT * 
    FROM inserted i  
        join product p1 on p1.model = i.model
        left outer join (
            select l.speed, l.code, p2.maker, p2.model 
            FROM laptop l 
                join product p2 on l.model = p2.model
        ) x
        on i.speed >= x.speed and p1.maker = x.maker and x.maker is NULL
    BEGIN 
        RAISERROR('Data integrity violation', 16, 1);
        ROLLBACK;
    END
GO