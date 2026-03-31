

```
1. Заявка в заявките 
2. case ... when ... then ... else ... end
3. [left] [outer/inter] join

4. count(distinct case when .. then [name] end )
5. sum(distinct case when .. then 1 else 0 end)

6. group by - класификации

7. .... is null
8. top 1 ... order by

```

❓ „За всяка…“ → от коя таблица почвам
❓ „Брой на…“ → COUNT или COUNT(DISTINCT)
❓ „най-много / най-голямо“ → MAX или ORDER BY + TOP 1
❓ „включително и без…“ → LEFT JOIN



```
 where name like 'C%'
 where name like '%wars%'

 where not exist 
 where count < all ( select ... )
 where count = any ( select ... )
```
