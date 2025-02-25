DROP SCHEMA IF EXISTS td1_qualite_nr CASCADE;

CREATE SCHEMA td1_qualite_nr;
SET SCHEMA 'td1_qualite_nr';

CREATE TABLE test_df (
  a VARCHAR(50),
  b VARCHAR(50),
  c VARCHAR(50),
  d VARCHAR(50)
);

INSERT INTO test_df (a, b, c, d) VALUES 
('a1', 'b1', 'c1', 'd1'),
('a2', 'b1', 'c2', 'd2'),
('a3', 'b2', 'c1', 'd3'),
('a4', 'b2', 'c1', 'd3'),
('a5', 'b2', 'c2', 'd4');

-- Ecrire la requête permettant pour chaque valeur de C de compter le nombre de valeurs de D.
SELECT c, COUNT(DISTINCT d) as nb_d FROM test_df GROUP BY c;


-- Ecrire une requête SQL permettant de vérifier que A → B.
SELECT a, COUNT(DISTINCT b) as nb_b FROM test_df GROUP BY a;
-- Il y a bien 1 seul b par a donc la dépendance fonctionnelle a->b est bien révifier.


CREATE TABLE test_df2 (
  a VARCHAR(50),
  b VARCHAR(50),
  c VARCHAR(50),
  d VARCHAR(50)
);

INSERT INTO test_df2 (a, b, c, d) VALUES 
('a1', 'b1', 'c1', 'd1'),
('a2', 'b1', 'c2', 'd2'),
('a3', 'b2', 'c1', 'd3'),
('a4', 'b2', 'c1', 'd5'),
('a5', 'b2', 'c2', 'd4');

-- Ecrire une requête permettant de lister les violations de la dépendance fonctionnelle B, C → D.
-- B,C->D
SELECT b
FROM test_df2 
GROUP BY b
HAVING COUNT(DISTINCT d) > 1

UNION

SELECT c
FROM test_df2
GROUP BY c
HAVING COUNT(DISTINCT d) > 1;
-- Cette requête affiche les n-uplets ou b et c on plus de 1 d différent.




-- Ecrire une requête permettant de compter le nombre d'enregistrements concernés par la violation de la
-- d´ependance fonctionnelle B, C → D est violée.
SELECT b, COUNT(DISTINCT d) as nb_d FROM test_df2 GROUP BY b
UNION
SELECT c, COUNT(DISTINCT d) as nb_d FROM test_df2 GROUP BY c;

-- La dépendance fonctionnelle est violé car il a plusieurs valeurs pour b2, c2, b1 et c1 alors 
-- qu'il devrait avoir 1 seul valeur de d pour chaque valeurs différentes de b ou de c.


-- Exercice 2
-- Identifier des dépendances fonctionnelles dans la relation "Pokémon".
/*
nom -> type, attaque
numpokmon -> nom, viv, dresseur
niv, nom -> pv

Dans cette échantillon donné il y a que des dépandances fonctionnelles.




Montrer à l'aide de plusieurs requˆetes SQL que NumPokemon est une clé.
*/
CREATE TABLE Pokemon (
    NumPokemon INT PRIMARY KEY,
    Nom VARCHAR(50) NOT NULL,
    Type VARCHAR(20) NOT NULL,
    Niveau INT NOT NULL,
    Attaque VARCHAR(50) NOT NULL,
    PV INT NOT NULL,
    Dresseur VARCHAR(50) NOT NULL
);

INSERT INTO Pokemon (NumPokemon, Nom, Type, Niveau, Attaque, PV, Dresseur) VALUES
(001, 'Bulbasaur', 'Grass', 10, 'Tackle', 45, 'Ash Ketchum'),
(002, 'Charmander', 'Fire', 8, 'Ember', 39, 'Gary Oak'),
(003, 'Squirtle', 'Water', 9, 'Water Gun', 44, 'Misty');


SELECT NumPokemon, COUNT(*) FROM Pokemon GROUP BY NumPokemon HAVING COUNT(*) > 1;
-- Cette requête ne renvoie rien mais c'est cela qui prouve que NumPokemon est une clé.


-- Proposition de la nouvelle conception.
CREATE TABLE _dresseur (
  id_dresseur INTEGER PRIMARY KEY,
  nom_dresseur VARCHAR(50)
);
CREATE TABLE _type (
  id_type INTEGER PRIMARY KEY,
  nom_type VARCHAR(50)
);
CREATE TABLE _attaque (
  id_attaque INTEGER PRIMARY KEY,
  nom_attaque VARCHAR(50)
);

CREATE TABLE _espece (
  nom VARCHAR(50) PRIMARY KEY,
  id_type INTEGER references _type(id_type),
  id_attaque INTEGER references _attaque(id_attaque)
);

CREATE TABLE _pokemon (
  numPokemon SERIAL,
  id_nom INTEGER references _espece(nom),
  niv INTEGER,
  id_dresseur INTEGER references dresseur(id_dresseur)
);

CREATE TABLE _point_de_vie (
  niv INTEGER,
  nom VARCHAR(50),
  PV INTEGER,
  PRIMARY KEY (niv, nom)
);



-- Exercie 4
/*
Name->Type, Level, Move, Power, Trainer, Location
Chaque Pokémon a un nom unique, ce qui détermine entièrement ses autres attributs.

Move->Power
Chaque attaque ("Move") a une puissance ("Power") fixe.

Name->Trainer
Un Pokémon appartient à un seul dresseur ("Trainer").

Trainer->Location
Chaque dresseur se trouve dans un seul lieu ("Location").
*/

-- Nouvelle décomposition que je propose pour respecter BCNF
CREATE TABLE _attaque (
    move VARCHAR(50) PRIMARY KEY,
    power INTEGER
);

CREATE TABLE _dresseur (
    trainer VARCHAR(50) PRIMARY KEY,
    location VARCHAR(50)
);

CREATE TABLE _pokemon (
    name VARCHAR(50) PRIMARY KEY,
    type VARCHAR(20),
    level INT,
    move VARCHAR(50),
    trainer VARCHAR(50),
    FOREIGN KEY (Move) REFERENCES _attaque(move)
);

CREATE TABLE _possession (
    trainer VARCHAR(50),
    name VARCHAR(50) UNIQUE,
    PRIMARY KEY (trainer, name),
    FOREIGN KEY (trainer) REFERENCES _dresseur(trainer),
    FOREIGN KEY (Name) REFERENCES _pokemon(name)
);


