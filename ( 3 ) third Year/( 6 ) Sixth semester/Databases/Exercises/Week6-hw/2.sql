

use csdb2026

-- 1

select distinct movie.TITLE, movie.[YEAR] from movie
    left outer join STARSIN on STARSIN.MOVIETITLE = movie.TITLE and STARSIN.MOVIEYEAR = movie.[YEAR]
where year <= 1982
    and not (STARSIN.STARNAME like '%k%' or STARSIN.STARNAME like '%b%')
group by movie.TITLE, movie.[YEAR]
order by movie.YEAR asc


-- 2

select movie.TITLE, movie.LENGTH from movie 
where movie.[YEAR] = (select movie.[YEAR] from movie
where title = 'Terms of Endearment')
    and (movie.LENGTH < (select movie.LENGTH from movie
where title = 'Terms of Endearment')
        or movie.LENGTH is null)



-- 3

select STARSIN.STARNAME from MOVIESTAR
    join MOVIEEXEC on MOVIEEXEC.NAME = MOVIESTAR.NAME
    join STARSIN on STARSIN.STARNAME = MOVIESTAR.NAME
group by STARSIN.STARNAME
having 
    min(STARSIN.MOVIEYEAR) < 1980
    and max(STARSIN.MOVIEYEAR) > 1985



-- 4

select mv.TITLE from movie mv
where INCOLOR = 'N' 
    and mv.[YEAR] <  (
        select min(m1.[YEAR]) 
        from movie m1
        where m1.INCOLOR = 'Y'
        group by STUDIONAME
        having m1.STUDIONAME = mv.STUDIONAME
        )



-- 5

select studio.NAME, studio.ADDRESS
from studio
    left join movie on movie.STUDIONAME = studio.NAME
    left join STARSIN on STARSIN.MOVIEYEAR = movie.[YEAR] and STARSIN.MOVIETITLE = movie.TITLE
group by studio.NAME, studio.ADDRESS
having count(distinct STARSIN.STARNAME) < 5
order by count(distinct starsin.STARNAME) desc


-- 6

select ships.NAME, ships.LAUNCHED from ships
where ships.NAME = ships.CLASS
    and not (ships.CLASS like '%i%' or ships.CLASS like '%k%')
order by ships.LAUNCHED DESC



-- 7 

select o.BATTLE from outcomes o
    left join ships on ships.NAME = o.SHIP
    left join classes on classes.CLASS = ships.CLASS
where o.SHIP = any (
    select e.SHIP from outcomes e
        left join ships on ships.NAME = e.SHIP
        left join classes on classes.CLASS = ships.CLASS
    where e.BATTLE = o.BATTLE
            and classes.COUNTRY = 'Japan'
            and e.RESULT = 'damaged')
group by o.BATTLE




-- 8 

select distinct ships.CLASS, ships.NAME from ships 
    left outer join classes og on og.CLASS = ships.CLASS
where ships.LAUNCHED = (
    select ships.LAUNCHED+1 from ships
    where ships.name = 'Rodney')
    and og.NUMGUNS > (
        select avg(classes.NUMGUNS) from ships
            left outer join classes on classes.CLASS = ships.CLASS
        where classes.COUNTRY = og.COUNTRY)

-- 9

select classes.CLASS from classes
    left outer join ships on ships.CLASS = classes.CLASS
    where classes.COUNTRY = 'USA'
group by classes.CLASS
having (max(ships.LAUNCHED) - min(ships.LAUNCHED)) >= 10


-- 10


select battles.NAME, classes.COUNTRY from BATTLES
    left outer join OUTCOMES on OUTCOMES.BATTLE = BATTLES.NAME
    left outer join ships on ships.name = outcomes.SHIP
    left outer join classes on classes.CLASS = ships.CLASS
group by Battles.NAME, classes.COUNTRY


-- 11
select battle, avg(ship_count) as avg_ships
from
(
select battles.NAME as 'battle', classes.COUNtry, count(*) as ship_count from BATTLES
     join OUTCOMES on OUTCOMES.BATTLE = BATTLES.NAME
     join ships on ships.name = outcomes.SHIP
     join classes on classes.CLASS = ships.CLASS
group by Battles.NAME, classes.COUNTRY
) c
group by battle


-- 12

-- country -> ships, battles, battles with sunk ships, 


select classes.COUNTRY,
    count(distinct ships.NAME),
    count(distinct case when outcomes.RESULT = 'sunk' then outcomes.battle end)
from classes 
    left join ships on ships.CLASS = classes.CLASS
    left join outcomes on outcomes.SHIP = ships.NAME
group by classes.COUNTRY


-- 13, 14
select MOVIESTAR.NAME, count(distinct movie.STUDIONAME) as 'studioes' from MOVIESTAR
    left outer join STARSIN on STARSIN.STARNAME = MOVIESTAR.NAME
    left outer join movie on movie.TITLE = STARSIN.MOVIETITLE and movie.[YEAR] = STARSIN.MOVIEYEAR
group by MOVIESTAR.NAME


-- 15

select MOVIESTAR.NAME from MOVIESTAR
    left outer join STARSIN on STARSIN.STARNAME = MOVIESTAR.NAME
    left outer join movie on movie.TITLE = STARSIN.MOVIETITLE
                            and movie.[YEAR] = STARSIN.MOVIEYEAR
group by MOVIESTAR.NAME
having 
    count(distinct case when movie.[YEAR] >= 1990 then movie.TITLE end) >=2


-- 16

select pc.model, max(pc.price) from pc
group by pc.model
order by max(pc.price) desc