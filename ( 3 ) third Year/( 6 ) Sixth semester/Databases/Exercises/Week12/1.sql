
-- Ако при добавяне на кораб, годината му на пускане на вода е > текущата, да се промени на NULL

GO

CREATE TRIGGER T_SHIP_1 ON SHIPS 
INSTEAD OF INSERT 
AS 
    INSERT INTO SHIPS (NAME, CLASS, LAUNCHED)
        SELECT 
         NAME,
         CLASS, 
         CASE 
            WHEN LAUNCHED > YEAR(GETDATE()) THEN NULL 
            ELSE LAUNCHED 
         END AS LAUNCHED
        FROM inserted
GO

CREATE TRIGGER T_SHIP_2 ON SHIPS 
AFTER INSERT 
AS
    UPDATE SHIPS 
    SET 
     LAUNCHED = NULL 
    WHERE NAME IN (SELECT NAME
                    FROM inserted
                    WHERE LAUNCHED > YEAR(GETDATE()))
GO


CREATE TRIGGER T_SHIP_1a on SHIPS 
INSTEAD OF INSERT 
AS 
    INSERT INTO SHIPS 
        SELECT * 
        FROM inserted 
        WHERE LAUNCHED <= YEAR(GETDATE())
        UNION
        SELECT NAME, CLASS, NULL 
        FROM inserted 
        WHERE LAUNCHED > YEAR(GETDATA())

GO



-- При променяа на черно-бял филм на цветен - продуценти да получи 1000000
-- АКО в една заявка са промени няколко филма на един продуцент
-- той да получи само ведднъж 1000000


CREATE TRIGGER T_MOVIE ON MOVIE
AFTER UPDATE 
AS 
    SELECT * FROM inserted
    SELECT * from deleted 
    IF UPDATE(INCOLOR)
    BEGIN 
        SELECT 1 
    END
GO 

BEGIN TRANSACTION
UPDATE MOVIE
SET
    INCOLOR = 'N'
WHERE YEAR < 1990
GO

CREATE OR ALTER TRIGGER T_MOVIE ON MOVIE 
AFTER UPDATE 
AS 
    IF UPDATE(TITLE) OR UPDATE(YEAR)
    BEGIN
        RAISERROR('TITTLE and YEAR are immutable.',16,1);
        ROLLBACK;
        RETURN;
    END

    SELECT * 
    FROM inserted i 
        JOIN deleted d on i.TITLE = d.TITLE and i.[YEAR] = d.[YEAR]
    where i.INCOLOR = 'Y' AND d.INCOLOR = 'N'


    UPDATE MOVIEEXEC
    SET
        NETWORTH += 100000
    WHERE CERT# IN (
        SELECT i. PRODUCERC#
        FROM inserted i
            JOIN deleted d on i.Title = d.TITLE and i.YEAR = d.[YEAR] 
        where i.INCOLOR = 'Y' AND d.INCOLOR = 'N'
    )
GO





BEGIN TRANSACTION
SELECT * FROM movie 

UPDATE MOVIE
SET  
    INCOLOR = CASE  
              WHEN STUDIONAME = 'MGM' THEN 'Y'
              WHEN STUDIONAME = 'Amazon studios' THEN 'Y'
              ELSE 'N'
            END
WHERE (TITLE = 'Empire Strikes Back' and Year = 1980)
    OR (TITLE = 'Gone WIth the Wind' and Year = 1938)
    OR (Title = 'The Tender Bar' and YEAR = 2021)


SELECT * FROM movie 
UPDATE MOVIE SET INCOLOR = 'N' where TITLE = 'Empire Strikes Back'

ROLLBACK
GO


CREATE TRIGGER T_OUTCOMES_1 ON OUTCOMES 
AFTER INSERT, UPDATE 
AS 
    IF EXISTS (SELECT * 
                FROM Ships s
                    join inserted i on s.name = i.SHIP 
                    join battles b on b.name = i.battle 
                 where LAUNCHED > YEAR(b.DATE)
                )
    BEGIN
        RAISERROR('Data integrity violation',16,1);
        ROLLBACK;
    END
    ELSE 
    BEGIN 
        IF NOT EXISTS ( SELECT 1 FROM deleted )
        BEGIN 
            INSERT INTO OUTCOMES 
                SELECT * FROM inserted
        END
            UPDATE o 
            SET
                o.RESULT = i.RESULT
            from outcomes o 
                JOIN inserted i on o.SHIP = i.SHIP and o.BATTLE = i.BATTLE

    END
GO