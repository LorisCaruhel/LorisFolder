DROP SCHEMA IF EXISTS td1_qualite_nr CASCADE;

CREATE SCHEMA td1_qualite_nr;
SET SCHEMA 'td1_qualite_nr';
 
/*
Exercice 1 :

+---+---+---+---+
| A | B | C | D |
+---+---+---+---+
| a1| b1| c1| d1|
| a1| b1| c1| d2|
| a1| b1| c2| d3|
| a2| b2| c2| d4|
| a2| b2| c2| d5|
+---+---+---+---+


Exercice 2 :
1) NumPokemon -> nom, attaque, niv, dresseur
nom -> type
nom, niv -> PV

2) NumPokemon+ = {nom, attaque, niv, dresseur, pv}

3) 
CREATE TABLE dresseur (
  dresseur_id SERIAL,
  dresseur_nom VARCHAR(50)
);

CREATE TABLE type (
  type_id SERIAL,
  type_nom VARCHAR(50)
);

CREATE TABLE pokemon  (
  numPokemon SERIAL,
  pokemon_nom VARCHAR(50),
  dresseur_id INTEGER references dresseur(dresseur_id),
  type_id INTEGER references type(type_id)
);

CREATE TABLE attaque  (
  attaque_id SERIAL,
  attaque_nom VARCHAR(50)
);

CREATE TABLE pokAttaque (
  numPokemon INTEGER references pokemon(numPokemon),
  attaque_id INTEGER references attaque(attaque_id)
);



Exercice 3 :

SELECT name, type
FROM pokemon
GROUP BY name
HAVING COUNT(DISTINCT type) > 1;


SELECT name, type 
FROM pokemon
WHERE name = 'Pikachu';
-- S'il y a plusieurs pikachu on va voir qu'ils ont tous le même type.












*/
