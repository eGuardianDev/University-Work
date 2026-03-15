

use movies

select * from studio

-- 1.1
select movie.STUDIONAME, STARSIN.STARNAME from starsin
join movie on movie.TITLE = starsin.MOVIETITLE
order by movie.STUDIONAME

-- 1.2
select distinct MOVIEEXEC.NAME from STARSIN
join MOVIE on movie.TITLE = STARSIN.MOVIETITLE and movie.YEAR = STARSIN.MOVIEYEAR
join MOVIEEXEC on MOVIEEXEC.CERT# = MOVIE.PRODUCERC#
where STARNAME = 'Harrison Ford'

-- 1.3
select distinct MOVIESTAR.NAME from MOVIESTAR
join STARSIN on STARSIN.STARNAME = MOVIESTAR.NAME
join MOVIE on MOVIE.TITLE = STARSIN.MOVIETITLE and MOVIE.[YEAR] = STARSIN.MOVIEYEAR
where MOVIESTAR.GENDER = 'F' and MOVIE.STUDIONAME = 'MGM'


-- 1.4
select movie.TITLE, MOVIEEXEC.NAME from movie 
join movieexec on movie.PRODUCERC# = movieexec.CERT#
where movieexec.NAME = (select MOVIEEXEC.NAME from Movie
                        join MOVIEEXEC on Movie.PRODUCERC# = MOVIEEXEC.CERT# 
                        where Movie.TITLE = 'Star Wars')


-- 1.5
select movie.TITLE, movie.YEAR, MOVIEEXEC.NAME from movie
left  join MOVIEEXEC on movie.PRODUCERC# = MOVIEEXEC.CERT# -- outer


-- 1.6
select movie.title, movie.[YEAR], MOVIEEXEC.NAME, STUDIO.NAME, STUDIO.ADDRESS from movie
left outer join STUDIO on movie.STUDIONAME = STUDIO.NAME
left outer join MOVIEEXEC on MOVIEEXEC.CERT# = movie.PRODUCERC#



-- 1.7
select * from MOVIESTAR
left outer join  STARSIN on STARSIN.STARNAME = MOVIESTAR.NAME
where STARSIN.MOVIETITLE is NULL 



-- 2.1

use pc

select product.model, pc.price from product
    left outer join PC on product.model = pc.model
where product.[type] = 'PC'



-- 2.2

select product.maker, product.model, product.[type] from product
    left outer join laptop on product.model = laptop.model
where laptop.price is null and product.type = 'Laptop'
union
select product.maker, product.model, product.[type] from product
    left outer join pc on product.model = pc.model
where pc.price is null and product.type = 'PC'
union 
select product.maker, product.model, product.[type] from product
    left outer join printer on product.model = printer.model
where printer.price is null and product.type = 'Printer'



-- 3.1

use ships


select ships.NAME, CLASSES.CLASS, classes.NUMGUNS,ships.LAUNCHED from ships
 left outer join CLASSES on ships.CLASS = classes.CLASS


-- 3.2

select OUTCOMES.SHIP from OUTCOMES
    left outer join BATTLES on BATTLES.NAME = OUTCOMES.BATTLE
where Year(BATTLES.DATE) = 1942
