drop schema if exists tp2r206 cascade;

create schema tp2r206;
set schema 'tp2r206';

create table _dept(
  nodept   integer       NOT NULL,
  nomdept  varchar(12)   NOT NULL,
  lieu     varchar(10)   NOT NULL,
  CONSTRAINT dept_pk PRIMARY KEY (nodept));

create table _personnel(
  matr    integer         NOT NULL,
  nome    varchar(10)     NOT NULL,
  sal     numeric(10,2)   NOT NULL,
  dateemb date            NOT NULL,
  comm    numeric(10,2)   NOT NULL,
  mondept integer         NOT NULL,
  CONSTRAINT _personnel_pk PRIMARY KEY (matr),
  CONSTRAINT personnel_travaille 
    FOREIGN KEY (mondept)
    REFERENCES _dept (nodept));

create table _president(
  matr  integer   NOT NULL,
  constraint _president_pk primary key(matr),
  constraint _president_fk_inherit 
    foreign key (matr) references _personnel(matr)
  );

create table _employe(
  matr   integer       NOT NULL,
  poste  varchar(10)   NOT NULL,
  sup    integer       NOT NULL,
  CONSTRAINT _employe_pk PRIMARY KEY (matr),
  CONSTRAINT employe_dirige 
    FOREIGN KEY (sup)
    REFERENCES _personnel (matr),
  CONSTRAINT employe_is_personnel 
    FOREIGN KEY (matr)
    REFERENCES _personnel (matr),
  CONSTRAINT employe_is_not_sup
    CHECK(matr <> sup)
);

-------- PEUPLEMENT
insert into _dept
  select *
  from tp1.dept;
  
insert into _personnel
  select matr, nome, sal, dateemb,comm, mondept
  from tp1.emp;
  
insert into _president
  select matr
  from tp1.emp
  where poste = 'PRESIDENT';
  -- ou matr n'est pas dans les sub de dirige
  
insert into _employe (matr, poste, sup)
  select matr, poste, sup
  from tp1.emp inner join tp1.dirige
  on matr = sub;

--- LES VUES

