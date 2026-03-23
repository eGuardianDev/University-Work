

use pc

-- 1.1
SELECT AVG(speed) AS avg_speed FROM PC;

-- 1.2
select product.maker, AVG(laptop.screen) from product
    right outer join laptop on laptop.model = product.model
GROUP BY product.maker

-- 1.3
select AVG(speed) as 'laptop_speed' from laptop
where price > 1000

-- 1.4
select AVG(pc.price) from pc 
    left OUTER JOIN product on product.model = pc.model
where product.maker = 'A'


-- 1.5 -- bad

select avg(m.price) as 'avg_price' from (select pc.price from pc 
    left OUTER JOIN product on product.model = pc.model
where product.maker = 'B'
union all -- keep duplicated !!!
select laptop.price from laptop 
    left OUTER JOIN product on product.model = laptop.model
where product.maker = 'B'
    ) m


-- 1.6
select speed, avg(price) from pc
group by speed

-- 1.7
select product.maker from product
where type = 'PC'
GROUP BY maker
HAVING count(model) >= 3 -- count(*)


-- 1.8
select distinct price, product.maker from pc
    left outer join product on product.model = pc.model
where pc.price = (select max(price) from pc)

-- 1.9
select pc.speed, avg(price) as 'price' from pc
where speed >= 800
group by pc.speed

-- 1.10
select avg(hd) as 'hdd_size' from pc
left outer join product on product.model = pc.model
where product.maker = any ( -- in 
        select distinct maker from product 
        where product.[type] = 'Printer'
    )


-- 1.11
select screen, (max(price) - min(price)) as 'price_diff' from laptop
group by screen 




use ships

-- 2.1
select count(*) as 'count_classes' from classes

-- 2.2
select avg(NUMGUNS) as 'avg_gun_number' from ships
left outer join classes on classes.class = ships.CLASS

-- 2.3
select ships.CLASS,  min(LAUNCHED) as 'earliest',max(LAUNCHED) as 'latest' from ships
-- left outer join classes on classes.CLASS = ships.CLASS -- unnecessary  
group by ships.class

-- 2.4
select ships.CLASS, count(*) from ships
-- left outer join classes on classes.CLASS = ships.CLASS - unnecessary
left outer join OUTCOMES on OUTCOMES.SHIP = ships.NAME
where OUTCOMES.RESULT = 'sunk'
group by ships.CLASS


-- 2.5

select ships.CLASS, count(*) as 'count_sunk' from outcomes
left outer join ships on ships.NAME = outcomes.SHIP
where ships.CLASS in 
    (
        select classes.CLASS from ships
        left outer join classes on classes.CLASS = ships.CLASS
        left outer join OUTCOMES on OUTCOMES.SHIP = ships.NAME
        group by classes.CLASS
        having count(*) > 4
    )
    and OUTCOMES.RESULT = 'sunk'
group by ships.CLASS

-- 2.6

select country, avg(DISPLACEMENT) from classes
group by COUNTRY



use movies

-- 3.1
select MOVIESTAR.NAME, count(distinct movie.STUDIONAME) from MOVIESTAR -- distinct because we don't want repeats (only unique)
right outer join STARSIN on STARSIN.STARNAME = MOVIESTAR.NAME --left/right
left outer join movie on movie.TITLE = STARSIN.MOVIETITLE and movie.[YEAR] = STARSIN.MOVIEYEAR
group by MOVIESTAR.NAME

-- 3.2

select MOVIESTAR.NAME, count(distinct movie.STUDIONAME) from MOVIESTAR -- distinct because we don't want repeats (only unique)
left outer join STARSIN on STARSIN.STARNAME = MOVIESTAR.NAME 
left outer join movie on movie.TITLE = STARSIN.MOVIETITLE and movie.[YEAR] = STARSIN.MOVIEYEAR
group by MOVIESTAR.NAME


-- 3.3

select MOVIESTAR.NAME from MOVIESTAR
left outer join STARSIN on STARSIN.STARNAME = MOVIESTAR.name
where STARSIN.MOVIEYEAR >= 1990
group by MOVIESTAR.NAME
having count(*) >=3

-- 3.4
use pc

select pc.model, max(pc.price) from pc
group by model  
order by max(price) desc

