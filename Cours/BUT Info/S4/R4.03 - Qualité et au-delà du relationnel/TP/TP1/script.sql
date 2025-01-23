DROP SCHEMA IF EXISTS tp1_qualite_nr CASCADE;

CREATE SCHEMA tp1_qualite_nr;
SET SCHEMA 'tp1_qualite_nr';

CREATE TABLE gamenn (
  gameid INTEGER,
  gametitle VARCHAR(60),
  gamerelease DATE,
  compname VARCHAR(60),
  charname VARCHAR(60)
);

WbImport -type=text
-file='/home/etuinfo/lcaruhel/Documents/github/LorisFolder/Cours/BUT Info/S4/R4.03 - Qualité et au-delà du relationnel/TP/TP1/design_tp_games.csv'
-delimiter=';'
-table=tp1_qualite_nr.gamenn;

-- Exercice 1 : 

-- Anomalie de redondance :
SELECT * FROM gamenn WHERE gameid = 18;
-- Le nom du jeux, la date de release, le nom de la compagnie et l'id de ce jeux, 
-- se répète autant de fois qu'il y a de charactère dans le jeux. 


-- Anomalie de MAJ :
SELECT * FROM gamenn WHERE charname = 'Mario';
UPDATE gamenn SET charname = 'Didier' WHERE gameid = 20645;
-- Le nom de mario est changé dans le jeux "Mario Kart Wii" mais pas dans les autres ou il apparaît.


-- Anomalie de suppression :
SELECT
  gametitle,
  COUNT(gameid)
FROM gamenn
GROUP BY gametitle
ORDER BY COUNT(gameid) ASC;
SELECT * FROM gamenn WHERE gametitle = 'Tail Concerto';
SELECT * FROM gamenn WHERE charname = 'Waffle Ryebread';

-- DELETE FROM gamenn WHERE charname = 'Waffle Ryebread';
-- Dès qu'on supprime un charactère qui n'est dans qu'un seul jeu,
-- on perd le jeu alors qu'on voulait juste supprimer le charactère.



-- Décomposition proposé : 
DROP TABLE IF EXISTS companies CASCADE;
DROP TABLE IF EXISTS games CASCADE;
DROP TABLE IF EXISTS characteres CASCADE;

CREATE TABLE companies (
  companieid INTEGER PRIMARY KEY,
  compname VARCHAR(60)
);

CREATE TABLE games (
  gameid INTEGER PRIMARY KEY,
  gametitle VARCHAR(60),
  gamerelease DATE,
  companieid INTEGER references companies(companieid)
);

CREATE TABLE characteres (
  charactereid INTEGER PRIMARY KEY,
  characterename VARCHAR(60)
);

CREATE TABLE appartient (
  gameid INTEGER references games(gameid),
  charactereid INTEGER references characteres(charactereid),
  PRIMARY KEY (gameid, charactereid)
);

CREATE TABLE est_coder_par (
  gameid INTEGER references games(gameid),
  companieid INTEGER references companies(companieid),
  PRIMARY KEY (gameid, companieid)
);

-- Relation entre un jeu et une companie : games(0..*)-----(1..*)companies
-- Donc table "est_coder_par"

-- Relation entre jeu et les charactères : games(0..*)-----(0..*)characteres
-- Donc table "appartient"


-- Exercice 2 : 
INSERT INTO companie(companieid, compname)
SELECT companieid, compname
FROM gamenn

INSERT INTO games(gameid, gametitle, gamerelease, companieid)
SELECT gameid, gametitle, gamerelease
FROM gamenn
INNER JOIN companie;

