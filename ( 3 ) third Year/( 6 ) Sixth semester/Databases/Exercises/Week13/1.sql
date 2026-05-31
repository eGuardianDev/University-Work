

Create Trigger T_PC 
ON PC 
After insert, update 
as 
    if exists(
        select *
        from inserted i
            Join product p1 on i.model = p1.model 
            left outer join 
            (
                select p2.maker, l.speed 
                from laptop l
                    Join product p2 on l.model = p2.model 
            ) sq on sq.speed >= i.speed and p1.maker = sq.maker
        where sq.maker is NULL
    )
    BEGIN 
        ROLLBACK;
        RAISERROR('Data integrity violation', 16,1);
    END
GO

-----------------------------------------
Create Trigger T_laptop_1
on laptop
after update 
as 
    Select * 
    from inserted i 
        join product p1 on i.model = p1.model 
        join deleted d on i.code = d.code 
        join product p2 on d.model = p2.model 
    where p1.maker <> p2.maker or i.speed < d.speed
go




Create Trigger T_laptop_1_
on laptop
after update 
as 
    Declare @failure tinyint = 0;

    with MakerToCheck AS(
        Select p2.maker 
        from inserted i      
            join product p1 on i.model = p1.model 
            join deleted d on i.code = d.code 
            join product p2 on d.model = p2.model 
        where p1.maker <> p2.maker or i.speed < d.speed
    ),
    PCMax as(
        Select p.maker, MAX(pc.speed) speed 
            from pc 
            join product p on pc.model = p.model
        where p.maker in (select maker from MakerToCheck)
        Group by p.maker
    ),
    LtMax as (
        Select p.maker, MAX(l.speed) speed 
        From laptop l 
            join product p on l.model = p.model 
        where p.maker in (select maker from MakerToCheck )
        group By p.maker
    )
    
    Select @failure = 1 
    from PcMax p 
        Join LtMax l on p.maker = l.maker 
    where p.speed > l.speed;

    if @failure = 1
    BEGIN
        RollBack;
        RAISERROR('Data integrity violation', 16, 1);
    END
go


-- one more about 2

Create Trigger T_PRODUCT_1
on product
after update, delete
as 
    Declare @failure tinyint = 0;

    with MakerToCheck AS(
        select maker from inserted where type = 'pc'
        union all 
        select maker from deleted where type = 'laptop'
    ),
    PCMax as(
        Select p.maker, MAX(pc.speed) speed 
            from pc 
            join product p on pc.model = p.model
        where p.maker in (select maker from MakerToCheck)
        Group by p.maker
    ),
    LtMax as (
        Select p.maker, MAX(l.speed) speed 
        From laptop l 
            join product p on l.model = p.model 
        where p.maker in (select maker from MakerToCheck )
        group By p.maker
    )
    
    Select @failure = 1 
    from PcMax p 
        Join LtMax l on p.maker = l.maker 
    where p.speed > l.speed or l.speed is null;

    if @failure = 1
    BEGIN
        RollBack;
        RAISERROR('Data integrity violation', 16, 1);
    END
go


Create Trigger T_PRODUCT_2
on product
after update, delete
as 
    Declare @failure tinyint = 0;

    with MakerToCheck AS(
        select maker from inserted where type = 'pc'
        union all 
        select maker from deleted where type = 'laptop'
    ),
    PCMax as(
        Select p.maker, MAX(pc.speed) speed 
            from pc 
            join product p on pc.model = p.model
        where p.maker in (select maker from MakerToCheck)
        Group by p.maker
    ),
    LtMax as (
        Select p.maker, MAX(l.speed) speed 
        From laptop l 
            join product p on l.model = p.model 
        where p.maker in (select maker from MakerToCheck )
        group By p.maker
    )
    
    Select @failure = 1 
    from PcMax p 
        Join LtMax l on p.maker = l.maker 
    where p.speed > l.speed or l.speed is null;

    if @failure = 1
    BEGIN
        RollBack;
        RAISERROR('Data integrity violation', 16, 1);
    END
go





Create Trigger T_PRODUCT_1_alt
on product
after update, delete
as 
    DECLARE @result tinyint = 0;
    DECLARE @makerToCheck StringBag;

    insert into @makerToCheck(
        Select inserted
    )
    
    Select @failure = 1 
    from PcMax p 
        Join LtMax l on p.maker = l.maker 
    where p.speed > l.speed or l.speed is null;

    if @failure = 1
    BEGIN
        RollBack;
        RAISERROR('Data integrity violation', 16, 1);
    END
go
