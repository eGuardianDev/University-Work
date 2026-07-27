

use movies 

-- 1
-- a
ALTER TABLE movie
ADD CONSTRAINT Unique_times_only UNIQUE (length);


-- b
ALTER TABLE MOVIE
ADD CONSTRAINT Unique_times_only UNIQUE (STUDIONAME, LENGTH);

select * from movie

insert into movie values('New movie', 1983, 112, 'Y', 'Fox', 555);



delete from movie
where title = 'New movie'


-- 2
alter table movie
drop CONSTRAINT Unique_times_only


-- 3

create database db_test
USE db_test;

create table students(
    fn int CHECK (fn BETWEEN 0 AND 99999),
    name varchar(100) NOT NULL,
    EGN char(10) UNIQUE NOT NULL,
    email varchar(100) UNIQUE NOT NULL,
    birthday DATE NOT NULL,
    acceptedData Date NOT NULL, 


    CONSTRAINT age_check check(acceptedData >= DATEADD(YEAR, 18, birthday)),
    -- b)
    CONSTRAINT email_check CHECK
    (
        email like ('%@%.%')
        and email not like ('@%.%')
        and email not like ('%@.%')
        and email not like ('%@%.')
    ),

    CONSTRAINT pk_students PRIMARY KEY (fn)
)

-- v)
create table courses(
    id int,
    name varchar(50),

    CONSTRAINT pk_courses PRIMARY KEY (id)
)

Create table doCourse(
    fn int not null,
    course_id int NOT NULL,

    CONSTRAINT pk_stundet_course PRIMARY KEY (fn,course_id),
    CONSTRAINT fk_sc_student FOREIGN KEY(fn)
        REFERENCES students(fn),
    CONSTRAINT fk_sc_course FOREIGN KEY(course_id)
        REFERENCES courses(id)
        on delete CASCADE
)

use movies
drop database db_test;