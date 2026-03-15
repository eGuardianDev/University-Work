


-- 1.1

use movies

select ms.NAME from MOVIESTAR ms
where ms.NAME = any (select me.NAME from MOVIEEXEC me where me.NETWORTH >=10000000 )


-- 1.2
select ms.NAME from MOVIESTAR ms
where ms.NAME != all (select me.NAME from MOVIEEXEC me)
-- not any 

-- 2.1
use pc

select distinct m.maker from product m 
where m.model = any (select model from PC where speed >= 500)  


-- 2.2
select * from laptop l
where l.speed < all (select p.speed from pc p )

-- 2.3
select top 1 model from 
    (
        select pr.model, pr.code, pr.price, 'printer' as type from printer pr
        union
        select lap.model, lap.code, lap.price, 'laptop' as type from laptop lap
        union
        select p.model, p.code, p.price, 'pc' as type from pc p
    ) as t  
order by t.price desc


-- 2.4

select product.maker from 
    (
        select * from printer p  
        where color = 'y' and p.price <= all (
                select price from printer 
                where color = 'y' )
    ) as t
    join product on product.model = t.model
order by t.price



-- 2.5

select product.maker from product
where product.model = any (
select model from pc
WHERE pc.ram <= ALL (SELECT ram FROM pc)
AND pc.speed >= ALL (
        SELECT speed
        FROM pc
        WHERE ram <= ALL (SELECT ram FROM pc)
))

-- 3.1

use ships


select distinct Country 
from classes
where numguns >= all (
        select numguns from classes
        )
-- order by numguns desc -- this doesn't work with distinct if the column isn't selected


-- 3.2

select * from ships
where class = any (
                select class from classes
                where bore = 16
                )

-- 3.3


select BATTLE from OUTCOMES
where  OUTCOMES.SHIP = any (
    select ships.NAME from ships
    where ships.CLASS = 'Kongo'
)
    

-- 3.4

select c.class from classes c
where c.NUMGUNS >= all(
    select c1.NUMGUNS from CLASSES c1
    where c1.BORE = c.BORE)


-- 3.5
select ships.NAME from ships
where ships.CLASS = any(
select c.CLASS from classes c
where c.NUMGUNS >= all(
    select c1.NUMGUNS from CLASSES c1
    where c1.BORE = c.BORE)
)
