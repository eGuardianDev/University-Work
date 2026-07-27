
-- 1

use ships

select classes.CLASS, 
    (
    select count(*)
    from classes
    left join ships on ships.CLASS = classes.CLASS
    where CLASSES.DISPLACEMENT > 30000
    group by classes.CLASS
    having count(distinct ships.LAUNCHED) > 3
    ) as 'big_ships',
    (
    select count(*)
    from classes
    left join ships on ships.CLASS = classes.CLASS
    left join OUTCOMES on outcomes.SHIP = ships.NAME
    group by classes.CLASS
    having count(distinct ships.LAUNCHED) > 3 and (outcomes.RESULT = 'ok' or outcomes.RESULT = 'damaged') 
    ) as 'winner_ships',
    (
    select count(*)
    from classes
    left join ships on ships.CLASS = classes.CLASS
    left join OUTCOMES on outcomes.SHIP = ships.NAME
    group by classes.CLASS
    having count(distinct ships.LAUNCHED) > 3 and ships.LAUNCHED > 1942 
    ) as 'AFTER_1942'
from classes
left join ships on ships.CLASS = classes.CLASS
group by classes.CLASS
having count(distinct ships.LAUNCHED) > 3




select 
    classes.CLASS,
    case when max(DISPLACEMENT) > 30000
        then count (distinct ships.NAME)
        else 0 end,
    -- sum( case when classes.DISPLACEMENT > 30000 then 1 else 0 end ) as 'big_ships',
    count(distinct case when outcomes.RESULT = 'ok' then ships.NAME end ) as 'won_battles',
    count(distinct case when ships.LAUNCHED > 1942 then ships.NAME  end ) as 'after_1942'
from classes
left join ships on ships.CLASS = classes.CLASS
left join outcomes on outcomes.SHIP = ships.NAME
group by classes.CLASS
having count(distinct ships.LAUNCHED) > 3 

-- 2

use pc

begin TRANSACTION

select * from pc

update pc 
set price = pc.price + 10 
where pc.ram > (

select top 1 ram from laptop
where laptop.screen = 14
order by price desc, ram desc
)

select * from pc
ROLLBACK


-- 3 

use ships 
go

create or alter view t_special_ships as
select s1.NAME, s1.CLASS, o1.BATTLE, 
    (
        select count(*)
        from outcomes o
        left join ships s on o.SHIP = s.NAME --
        left join classes on classes.CLASS = s.CLASS --
        where o.BATTLE = o1.BATTLE and classes.NUMGUNS > 8
    ) as 'Ships_with_8+_guns',
    s1.LAUNCHED, battles.[DATE] 
from ships s1
left join outcomes o1 on s1.NAME = o1.SHIP
left join battles on battles.NAME = o1.BATTLE
left join classes on classes.CLASS = s1.CLASS -- 
where classes.NUMGUNS > 8 -- 
go


-- 4
    

create or alter trigger t_outcomes_special
on outcomes 
instead of update 
as 
BEGIN TRANSACTION


    update outcomes
    set 
        outcomes.RESULT = i.result
    from outcomes
    inner join inserted i 
    on i.battle = outcomes.battle
        and i.ship = outcomes.ship

    if exists (
        select *
        from outcomes 
        left join battles on BATTLES.NAME = outcomes.BATTLE
        left join ships on ships.NAME = outcomes.SHIP
        left join classes on ships.CLASS = classes.CLASS
        where Year(battles.[DATE]) > 1941 and classes.NUMGUNS < 10
    )
        RAISERROR('Cannot have ships with less than 10 guns after 1941', 16,1)
        ROLLBACK

end
go