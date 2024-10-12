drop schema if exists distribill cascade;
create schema distribill;
set schema 'distribill';

CREATE TABLE fournisseur (
  nofour  CHAR(3),
  nomf    VARCHAR(20) NOT NULL,
  ville   VARCHAR(20) NOT NULL,
  CONSTRAINT fournisseur_pk PRIMARY KEY(nofour)
);

INSERT INTO fournisseur VALUES('F1','Bourhis','Paris');
INSERT INTO fournisseur VALUES('F2','Bourhis','Paris');
INSERT INTO fournisseur VALUES('F3','Collet','Reims');
INSERT INTO fournisseur VALUES('F4','Bossuet','Dijon');
INSERT INTO fournisseur VALUES('F5','Mercier','Riec');
INSERT INTO fournisseur VALUES('F6','Tanguy','Lannion');

create table produit(
  noproduit CHAR(3) primary key,
  nomp      VARCHAR(20) NOT NULL,
  origine   VARCHAR(20) NOT NULL,
  couleur   VARCHAR(20) NOT NULL
);


INSERT INTO produit(noproduit,nomp,couleur,origine) 
	VALUES('P1','Cassis','Rouge','Dijon');
INSERT INTO produit(noproduit,nomp,couleur,origine) 
	VALUES('P2','Champagne','Blanc','Reims');
INSERT INTO produit(noproduit,nomp,couleur,origine) VALUES
  ('P3','Huitre','Vert','Riec'),
	('P4','Moutarde','Jaune','Dijon'),
	('P5','Salade','Vert','Nice'),
	('P6','Cornichon','Vert','Dijon'),
	('P7','Muscadet','Blanc','Nantes');


create table fourniture(
  nofour      char(3),
  noproduit   char(3),
  quantite    INTEGER NOT NULL,
  constraint fourniture_pk primary key(nofour, noproduit)
);

INSERT INTO fourniture VALUES ('F1','P1',1);
INSERT INTO fourniture VALUES ('F1','P4',1);
INSERT INTO fourniture VALUES ('F1','P5',8);
INSERT INTO fourniture VALUES ('F1','P6',2);
INSERT INTO fourniture VALUES ('F2','P2',1);
INSERT INTO fourniture VALUES ('F2','P4',1);
INSERT INTO fourniture VALUES ('F3','P2',5);
INSERT INTO fourniture VALUES ('F3','P4',1);
INSERT INTO fourniture VALUES ('F4','P4',2);
INSERT INTO fourniture VALUES ('F4','P5',7);
INSERT INTO fourniture VALUES ('F4','P6',3);
INSERT INTO fourniture VALUES ('F5','P3',10);

/*
INSERT INTO fourniture VALUES ('F1','P1',2); -- pb de clé : normal
INSERT INTO fourniture VALUES ('F12','P1',2); -- pas de pb : pas normal, il manque une FK
*/

/* 
delete from fourniture where nofour = 'F12';
*/
alter table fourniture
  add constraint fourniture_fk_fournisseur
  foreign key(nofour) references fournisseur(nofour);
  
alter table fourniture
  add constraint fourniture_fk_produit
  foreign key(noproduit) references produit(noproduit);
  

-- 1.Quels sont les noms des produits commercialisés par l'entreprise ?
select distinct nomp
from produit;

-- 2.Quels sont les produits originaires de 'Dijon' ?
select *
from produit
where origine = 'Dijon';

-- 3.Quels sont les noms des produits originaires de 'Dijon' ?
select distinct nomp
from produit
where origine = 'Dijon';

-- 4.Quels sont les numéros des fournisseurs qui fournissent quelque chose ?
select distinct nofour
from fourniture;

-- 5.Quels sont les numéros des fournisseurs qui ne fournissent rien ?
select nofour
from fournisseur
except
select nofour
from fourniture;

-- 6.Quels sont les numéros des fournisseurs qui fournissent au moins le produit 'P6' ?
select nofour
from fourniture
where noproduit = 'P6';

-- 7.Quels sont les numéros des fournisseurs qui fournissent quelque chose d'autre que 'P6' ?
select distinct nofour
from fourniture
where noproduit <> 'P6'
order by nofour asc; -- asc ou desc pour ascendant ou descendant.

-- 8.Quels sont les numéros des fournisseurs qui ne fournissent pas 'P6' ?
select nofour
from fournisseur
except
select nofour
from fourniture
where noproduit = 'P6';

-- 9.Quels sont les numéros des fournisseurs qui fournissent quelque chose mais pas 'P6' ?
select nofour
from fourniture
except
select nofour
from fourniture
where noproduit = 'P6';

-- 10.Quels sont les numéros des Fournisseurs qui ne fournissent que 'P6' ?
select nofour
from fourniture
except
select nofour
from fourniture
where noproduit <> 'P6';

-- 11.Quels sont les numéros des fournisseurs qui fournissent 'P4' ou 'P6' ?
select distinct nofour
from fourniture
where noproduit = 'P6' or noproduit = 'P4';

-- ou

select distinct nofour
from fourniture
where noproduit = 'P6' 
union
select distinct nofour
from fourniture
where noproduit = 'P4'; 

-- 12.Quels sont les numéros des fournisseurs qui fournissent 'P4' et 'P6' ?
select distinct nofour
from fourniture
where noproduit = 'P6' and noproduit = 'P4';

-- ou

select distinct nofour
from fourniture
where noproduit = 'P6' 
intersect
select distinct nofour
from fourniture
where noproduit = 'P4'; 

-- 13.Quels sont les numéros des fournisseurs qui ne fournissent ni 'P4' ni 'P6' ?
select distinct nofour
from fourniture
except(
  select nofour
  from fourniture
  where noproduit = 'P4'
  union
  select nofour
  from fourniture
  where noproduit = 'P6');


-- 14.Quels sont les numéros et noms des fournisseurs qui fournissent 'P6
-- Jointure naturelle :
select noproduit, nomf
from fournisseur natural join fourniture
where noproduit = 'P6';

-- OU

select fournisseur.nofour, nomf
from fournisseur inner join fourniture
on fournisseur.nofour = fourniture.nofour
where noproduit = 'P6';

-- En utilisant des alias
select f.nofour, nomf
from fournisseur f inner join fourniture ft
on f.nofour = ft.nofour
where noproduit = 'P6';

-- 15.Quels sont les numéros et noms des fournisseurs qui ne fournissent ni 'P4' ni 'P6' ?
select nofour, nomf
from fournisseur
except
select nofour, nomf
from fournisseur natural join fourniture
where noproduit = 'P6' or noproduit = 'P4';

-- inner join
select nofour, nomf
from fournisseur
except
select fournisseur.nofour, nomf
from fournisseur inner join fourniture
on fournisseur.nofour = fourniture.nofour
where noproduit = 'P6' or noproduit = 'P4';

-- 16.Quels sont les numéros, noms et villes des fournisseurs qui fournissent au moins un produit originaire de leur ville ?
select nofour, nomf, ville
from fournisseur natural join fourniture natural join produit
where ville = origine;

select nofour, nomf, ville
from fournisseur f inner join fourniture ft on f.nofour = ft.nofour
                    inner join produit p on ft.noproduit = p.noproduit
where ville = origine;

-- 17.Quels sont les produits qui sont de même couleur ? Le résultat sera présenté par des couples de numéros de produits.
select p1.noproduit as n1, p2.noprodruit as n2
from produit p1 inner join produit p2
  on p1.couleur = p2.couleur
where p1.noproduit < p2.noproduit;

-- 18.Quels sont les produits de même couleur que la salade (certaines salades sont rouges, d'autres vertes...) ?
select p1.*
from produit p1 inner join produit salade
on p1.couleur = salade.couleur
where salade.nomp = 'Salade' and p1.noproduit <> salade.noproduit;

with couleur_salade as(
  select couleur
  from produit
  where nomp = 'Salade')
select *
from produit natural join couleur_salade;

-- 19.Quels sont les numéros des fournisseurs qui fournissent des produits verts ou rouges ?
select distinct nofour
from fourniture natural join produit
where couleur = 'Vert' or couleur = 'Rouge';

select nofour
from fourniture natural join produit
where couleur = 'Vert'
union
select nofour
from fourniture natural join produit
where couleur = 'Rouge';

with pdts_verts_ou_rouges as (
  select noproduit
  from produit
  where couleur = 'Vert' or couleur = 'Rouge')
select distinct nofour
from fourniture natural join pdts_verts_ou_rouges;

-- 20.Quels sont les numéros des fournisseurs qui fournissent des produits verts et rouges ?
-- Pas de sens car un produit n'a qu'une couleur

-- 21.Quels sont les numéros et noms des fournisseurs qui ne fournissent pas de produit vert ?
select nofour, nomf
from fournisseur
except
select nofour, nomf
from fournisseur natural join fourniture natural join produit
where couleur = 'Vert';

select nofour, nomf
from fournisseur 
where nofour not in (
  select nofour
  from fourniture natural join produit
  where couleur = 'Vert'
);

-- 22.Quels sont les numéros et noms des fournisseurs qui ne fournissent que des produits verts ?
select nofour, nomf
from fournisseur natural join fourniture
except
select nofour, nomf
from fournisseur natural join fourniture natural join produit
where couleur <> 'Vert';

select nofour, nomf
from fournisseur
where nofour not in (
  select nofour
  from fourniture natural join produit
  where couleur <> 'Vert'
);

-- 23.Quels sont les numéros et noms des fournisseurs qui ne fournissent que des produits verts ou jaunes ?
select nofour, nomf
from fournisseur natural join fourniture
except
select nofour, nomf
from fournisseur natural join fourniture natural join produit
where couleur <> 'Vert' and couleur <> 'Vert';

select nofour, nomf
from fournisseur
where nofour not in (
  select nofour
  from fourniture natural join produit
  where couleur <> 'Vert' and couleur <> 'Jaune'
);
