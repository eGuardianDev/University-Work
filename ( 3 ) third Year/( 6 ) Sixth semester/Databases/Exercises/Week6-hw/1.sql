

-- 1
select 
	case 
		when YEAR(birthdate) <(1960) then 'Before 60s'
		when Year(BIRTHDATE) >= 1960 and Year(BIRTHDATE) < 1970 then '60s'
		when Year(BIRTHDATE) >= 1970 and Year(BIRTHDATE) < 1980 then '70s'
		when Year(BIRTHDATE) >= 1980 then 'After 70s'
	end,
	count(*) as 'StarCount' from moviestar
	group by 
	case 
		when YEAR(birthdate) <(1960) then 'Before 60s'
		when Year(BIRTHDATE) >= 1960 and Year(BIRTHDATE) < 1970 then '60s'
		when Year(BIRTHDATE) >= 1970 and Year(BIRTHDATE) < 1980 then '70s'
		when Year(BIRTHDATE) >= 1980 then 'After 70s'
	end



-- 2
select outcomes.BATTLE, count(ships.NAME)
from OUTCOMES
	left join ships on OUTCOMES.SHIP = ships.NAME
	left join classes on ships.CLASS = classes.CLASS
group by outcomes.BATTLE
having sum(case when classes.NUMGUNS <=9 then 1 else 0 end) >= 3
   and sum(case when classes.NUMGUNS <= 9 and OUTCOMES.RESULT = 'ok' then 1 else 0 end) >= 2


select outcomes.BATTLE, count(ships.NAME)
from OUTCOMES
	left join ships on OUTCOMES.SHIP = ships.NAME
	left join classes on ships.CLASS = classes.CLASS
where CLASSES.NUMGUNS <= 9
group by outcomes.BATTLE
having count(*) >=3 and (sum(case when outcomes.result = 'ok' then 1 else 0 end) >=2)




-- 3.1

select outcomes.BATTLE, count(distinct ships.NAME) from outcomes
	left outer join ships on ships.NAME = outcomes.SHIP
	left outer join classes on classes.CLASS = ships.CLASS
where outcomes.RESULT = 'sunk'
group by OUTCOMES.BATTLE, classes.COUNTRY
HAVING classes.COUNTRY = 'USA'
	and count(case when outcomes.RESULT = 'sunk' then 1 else 0 end) >= 1


-- 3.2

select outcomes.BATTLE from outcomes
	left outer join ships on ships.NAME = outcomes.SHIP
	left outer join classes on classes.CLASS = ships.CLASS
group by outcomes.BATTLE, classes.COUNTRY
having count(distinct outcomes.SHIP) >=3


-- 3.3


select ships.CLASS from ships
group by ships.class
having count(ships.NAME) >0
	and sum(case when ships.LAUNCHED > 1921 then 1 else 0 end) = 0


-- 3.4

select SHIPS.NAME, sum(case when outcomes.RESULT = 'damaged' then 1 else 0 end) as 'damaged'
from ships
	left outer join outcomes on outcomes.SHIP = ships.NAME
group by ships.NAME


-- select SHIPS.NAME from ships
-- 	left outer join outcomes on outcomes.SHIP = ships.NAME
-- group by ships.NAME
-- having sum(case when outcomes.RESULT = 'damaged' then 1 else 0 end) >=1


-- 3.5


select country,count(distinct ships.NAME) as 'ship count', 
		-- sum(distinct case when outcomes.RESULT = 'sunk' then 1 else 0 end) as 'sunked count'
		count(distinct case when outcomes.RESULT = 'sunk' then ships.name end) as 'sunk count'
from ships
	left outer join classes on classes.CLASS = ships.CLASS
	left outer join OUTCOMES on outcomes.SHIP = ships.NAME
group by COUNTRY


-- 3.6

select  count(distinct case when outcomes.RESULT = 'damaged' then ships.name end) as 'damaged count',
		count(distinct case when outcomes.RESULT = 'sunk' then ships.name end) as 'sunked count'
from ships
	left outer join classes on classes.CLASS = ships.CLASS
	left outer join OUTCOMES on outcomes.SHIP = ships.NAME
group by COUNTRY


-- 3.7


select classes.CLASS,
	count(distinct case when outcomes.RESULT = 'ok' then ships.NAME end) as 'ok ships'
from classes
	left outer join ships on classes.class = ships.CLASS
	left outer join outcomes on ships.NAME = outcomes.SHIP 
group by classes.CLASS
	having count(distinct ships.NAME) >=3


-- 3.8


select ms.NAME, ms.BIRTHDATE,
	(
		select TOP 1 studio.NAME from studio
			left outer join movie on movie.STUDIONAME = studio.NAME	
			left outer join STARSIN on movie.TITLE = STARSIN.MOVIETITLE
									and movie.[YEAR] = STARSIN.MOVIEYEAR
		where STARSIN.STARNAME = ms.name 
		group by studio.NAME 
		order by count(*) desc
	) de
from moviestar ms


-- 3.9

-- use pc

-- select product.maker from product
-- 	left outer join pc on pc.model = product.model
-- group by maker


-- select * from printer
-- 	left outer join product on product.model = printer.model 
-- where printer.[type] = 'Laser'


-- 3.10