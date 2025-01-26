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
-file='<chemin absolue vers le CSV>'
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
  companieid SERIAL PRIMARY KEY,
  compname VARCHAR(60)
);

CREATE TABLE games (
  gameid INTEGER PRIMARY KEY,
  gametitle VARCHAR(60),
  gamerelease DATE
);

CREATE TABLE characteres (
  charactereid SERIAL PRIMARY KEY,
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

-- Relation entre jeu et les charactères : games(0..*)-----(1..*)characteres
-- Donc table "appartient"


-- Exercice 2 : 
INSERT INTO companies(compname)
SELECT DISTINCT compname
FROM gamenn;

INSERT INTO games(gameid, gametitle, gamerelease)
SELECT DISTINCT gameid, gametitle, gamerelease
FROM gamenn g;

INSERT INTO characteres(characterename)
SELECT DISTINCT charname
FROM gamenn g;

INSERT INTO appartient(gameid, charactereid)
SELECT DISTINCT gameid, charactereid
FROM gamenn g
INNER JOIN characteres c
ON g.charname = c.characterename;

INSERT INTO est_coder_par(gameid, companieid)
SELECT DISTINCT gameid, companieid
FROM gamenn g
INNER JOIN companies c
ON g.compname = c.compname;



-- Compter les n-uplets :
-- Une seule requête pour obtenir le nombre de n-uplets pour chaque table
SELECT 'companies' AS table, COUNT(*) AS nb_lignes FROM companies
UNION ALL
SELECT 'games' AS table, COUNT(*) AS nb_lignes FROM games
UNION ALL
SELECT 'characteres' AS table, COUNT(*) AS nb_lignes FROM characteres
UNION ALL
SELECT 'appartient' AS table, COUNT(*) AS nb_lignes FROM appartient
UNION ALL
SELECT 'est_coder_par' AS table, COUNT(*) AS nb_lignes FROM est_coder_par
UNION ALL

SELECT 
    'Total schéma proposé' AS table, 
    SUM(nb_lignes) AS total_rows
FROM (
    SELECT COUNT(*) AS nb_lignes FROM companies
    UNION ALL
    SELECT COUNT(*) AS nb_lignes FROM games
    UNION ALL
    SELECT COUNT(*) AS nb_lignes FROM characteres
    UNION ALL
    SELECT COUNT(*) AS nb_lignes FROM appartient
    UNION ALL
    SELECT COUNT(*) AS nb_lignes FROM est_coder_par
) AS counts

UNION ALL

SELECT 
    'gamenn' AS table, 
    COUNT(*) AS nb_lignes
FROM gamenn;

-- Grâce au schéma que j'ai proposé on voit qu'il y a déjà une améliration de 3000 n-uplets en moins.



--Compter le nombre d'octets des tables : 
SELECT 
    'Total du schéma proposé' AS table, 
    SUM(taille_octet) AS taille_octet
FROM (
    SELECT pg_total_relation_size('companies') AS taille_octet
    UNION ALL
    SELECT pg_total_relation_size('games') AS taille_octet
    UNION ALL
    SELECT pg_total_relation_size('characteres') AS taille_octet
    UNION ALL
    SELECT pg_total_relation_size('appartient') AS taille_octet
    UNION ALL
    SELECT pg_total_relation_size('est_coder_par') AS taille_octet
) AS taille_octet

UNION ALL

SELECT 
    'gamenn' AS table, 
    pg_total_relation_size('gamenn') AS taille_octet;
    

-- Différence de taille est de  2 260 992 - 1 638 400 = 622 592 octets.

