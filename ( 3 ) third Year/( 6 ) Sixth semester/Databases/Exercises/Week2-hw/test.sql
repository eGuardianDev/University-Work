
use movies

SELECT TITLE, YEAR, STUDIONAME, ADDRESS AS STDUIOADDRESS
FROM MOVIE, STUDIO 
WHERE STUDIONAME = NAME AND INCOLOR = 'Y'
-- SELECT * FROM MOVIE, STUDIO 


use pc
-- 4

select distinct pc0.model, pc1.model from pc as pc0
	join pc as pc1 on pc0.speed = pc1.speed and pc0.ram = pc1.ram and pc0.model < pc1.model
order by pc0.model

-- 5
select product.maker
from pc as pc0
join product on pc0.model = product.model
where pc0.speed >= 500
group by product.maker
having count(distinct pc0.model) >= 2;


select distinct pr0.maker from pc as pc0
    join product as pr0 on pr0.model = pc0.model
    join pc as pc1 on pc1.model != pc0.model
    join product as pr1 on pr1.model = pc1.model
where pc0.speed >=500 and pc1.speed >= 500 and pr0.maker = pr1.maker


-- ex 3

use ships

-- 1
select NAME from ships
    join classes on classes.CLASS = ships.CLASS
where DISPLACEMENT >=35000


-- 2
select ships.name, classes.DISPLACEMENT, classes.NUMGUNS from ships
    join OUTCOMES on ships.NAME = OUTCOMES.SHIP
    join BATTLES on OUTCOMES.BATTLE = BATTLES.NAME
    join CLASSES on classes.CLASS = ships.CLASS
where battles.NAME = 'Guadalcanal'


-- 3
select * from ships
    join CLASSES on classes.CLASS = ships.CLASS
where classes.type = 'bb' or classes.type = 'bc'


-- 4 
-- select * from ships

-- select * from BATTLES

select o1.SHIP
from OUTCOMES as o1 
JOIN BATTLES as b1 on o1.BATTLE = b1.NAME
join OUTCOMES as o2 on o1.ship = o2.ship 
JOIN BATTLES as b2 on o2.BATTLE = b2.NAME
where o1.RESULT ='damaged' 
    and b2.date > b1.date








