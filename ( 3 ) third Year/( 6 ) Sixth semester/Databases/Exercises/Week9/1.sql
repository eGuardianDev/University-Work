



-- Create table 

-- int, integer 32bit
-- bigint, 64-bit
-- float 
-- decimal(n,d) -- n - all digits -- d - after decimal
-- date, time, datetime
-- datetime2 
-- json
-- geometry
-- geography
-- hiearchyid
-- money
-- bit 
-- char(n)
-- varchar(n)

-- varchar(max)
-- nvarchar(max)

-- binary(n)
-- varbinary(n)
-- images



IF OBJECT_ID('Customer') IS NOT NULL DROP TABLE Customer
IF OBJECT_ID('Employees') IS NOT NULL DROP TABLE Employees
IF OBJECT_ID('Products') IS NOT NULL DROP TABLE Products
IF OBJECT_ID('Orders') IS NOT NULL DROP TABLE Orders
IF OBJECT_ID('OrderItems1') IS NOT NULL DROP TABLE OrderItems1
IF OBJECT_ID('OrderItems2') IS NOT NULL DROP TABLE OrderItems2
IF OBJECT_ID('OrderItems3') IS NOT NULL DROP TABLE OrderItems3




-- PRIMARY KEY CONSTRAINT
-- UNIQUE CONSTRAINT
-- FOREIGN KEY CONSTRAINT 
-- CHECK CONSTRAINT
-- DEFAULT CONSTRAINT

-- 


Create Table Customer(
    CustomerID int IDENTITY(1,1) PRIMARY KEY,
    FirstName varchar(32),
    LastName varchar(32),
    Email varchar(64)
)




CREATE TABLE Employees(
    EmplyeeID int IDENTITY,
    FirstName varchar(32),
    LastName varchar(32),
    Email varchar(64),
    Title varchar(32),
    HireDate date,
    MaangerID int
)


Create Table Products(
    ProductID int IDENTITY,
    Title varchar(64),
    ListPrice decimal(16,2),
    CONSTRAINT PK_Products primary key(ProductID)
)

Create table Orders(
    OrderID int IDENTITY,
    CustomerID int,
    EmployeeID int,
    OrderDate date,
    DeliveryDate date
)

alter table Orders add CONSTRAINT PK_Orders primary key(OrderID)

Create Table OrderItems1(
    OrderID int,
    ProductID int,
    UnitPrice decimal(16,2),
    Quantity int,
    Discount decimal(16,2)
    Primary key(OrderID, ProductID)
    CONSTRAINT CC_UnitPrice check (UnitPrice > 0)
)

Create Table OrderItems2(
    OrderID int,
    LineNumber int,
    ProductID int,
    UnitPrice decimal(16,2),
    Quantity int,
    Discount decimal(16,2)
    Primary key(OrderID, LineNumber),
    UNIQUE(OrderID, ProductID)
    -- CONSTRAINT UC_OrderItems2 UNIQUE(OrderID, ProductID)
)



select * from Customer
insert into Customer(FirstName, LastName, Email)
    Values('John', 'Smith', 'j.smith@corp1.com')

insert into Customer(FirstName, LastName)
    Values('Hellen', 'Schmidth')


Insert into Products 
    Values('Bike',212.99)

Insert into Orders (CustomerID, EmployeeID, OrderDate)
    Values(1,1,GetDate())

select * from Orders


insert into OrderItems1
    Values(1,1, 212.99, 1,0)

select * from OrderItems1


insert into orders(CustomerID, EmployeeID, OrderDate) VALUES(1,1, '2026-01-01')

select * from orders



ALTER TABLE CUSTOMER ADD RegistrationDate DATETIME;
ALTER TABLE CUSTOMER DROP COLUMN RegistrationDate;
Alter table Customer add RegistrationDate DATETIME default GETDATE();

ALTER TABLE CUSTOMER DROP CONSTRAINT DF__Customer__Regist__71D1E811

ALTER TABLE CUSTOMER DROP COLUMN RegistrationDate;
-- sp_help 'CUSTOMER'

select * from Customer
