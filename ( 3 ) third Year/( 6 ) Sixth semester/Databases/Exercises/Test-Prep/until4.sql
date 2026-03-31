
-- 1
select name, LAUNCHED from ships
where ships.NAME = ships.CLASS


-- 2
select * from movie
where movie.TITLE like '%Trek%' and movie.TITLE like '%Star%'
order by year asc, movie.TITLE asc


-- 3
select distinct movie.TITLE, movie.[YEAR] from movie
    left outer join STARSIN on STARSIN.MOVIETITLE = movie.TITLE
                            and STARSIN.MOVIEYEAR = movie.[YEAR]
    left outer join MOVIESTAR on STARSIN.STARNAME = moviestar.NAME
where Year(moviestar.BIRTHDATE) >= 1970 and moviestar.BIRTHDATE <= '1980-7-1'

-- 4
select ships.name from ships
    left outer join outcomes on outcomes.SHIP = ships.NAME
where 
        (ships.NAME like 'C%' or ships.NAME like 'K%')
group by ships.NAME
having count(*) >=1


-- 5
select country from ships
    left outer join classes on classes.CLASS = ships.CLASS
    left outer join outcomes on outcomes.SHIP = ships.NAME
group by country
having sum(case when outcomes.RESULT = 'sunk' then 1 else 0 end) > 0

-- 6
select country from ships
    left outer join classes on classes.CLASS = ships.CLASS
    left outer join outcomes on outcomes.SHIP = ships.NAME
group by country
having sum(case when outcomes.RESULT = 'sunk' then 1 else 0 end) = 0


-- 7


select classes.CLASS 
from classes
where not exists (
    select * 
    from ships
    where classes.CLASS = ships.CLASS and ships.LAUNCHED > 1920 
) 

-- 8 

select ships.NAME, classes.COUNTRY, classes.BORE from ships 
    left outer join classes on classes.CLASS= ships.CLASS
where classes.NUMGUNS = 6
    or classes.NUMGUNS = 8
    or classes.NUMGUNS = 10


-- 9
select country from classes
group by COUNTRY
having count(distinct classes.BORE) > 1


-- 10

select country from classes
group by country 
having max(classes.NUMGUNS) = (
    select max(NUMGUNS) from classes
)

-- 11

use pc 

select pc.model, pc.price
 from pc
    left outer join product p1 on p1.model = pc.model
where pc.price < (
    select min(price) from laptop 
        left outer join product p2 on p2.model = laptop.model
        where p1.maker = p2.maker
)
order by pc.price desc

SELECT pc.model, pc.price
FROM pc
JOIN product p1 ON pc.model = p1.model
WHERE pc.price < ALL (
    SELECT l.price
    FROM laptop l
    JOIN product p2 ON l.model = p2.model
    WHERE p1.maker = p2.maker
)
order by pc.price desc

-- 12

select count(*) from pc
    left outer join product p1 on p1.model = pc.model
where pc.price < (select min(producing.price) from (
select min(price) as price from laptop 
    left outer join product on product.model = laptop.model
    where product.maker = p1.maker
union all
select min(price) as price from printer 
    left outer join product on product.model = printer.model
    where product.maker = p1.maker
) producing)
