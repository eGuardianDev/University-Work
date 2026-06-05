
-- 1

Create database test


-- 2

-- a)
create table Product(
    maker varchar(4),
    model char(1),
    type varchar(4)
);
create table Printer(
    code  int, 
    model varchar(4),
    color char(1) default('n'),
    price decimal(8,2)
);
create table Classes(
    class varchar(50), 
    type  char(2)
)


-- 3

Insert into printer (code, model) values 
(1, 'cat1')


-- 4
alter table classes 
add Bore decimal(8,2)


-- 5
alter table printer 
drop column price

select * from printer


-- 6

drop table printer 
drop table product
drop table classes
drop database test 