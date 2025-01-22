DROP SCHEMA IF EXISTS tp1_qualite_nr CASCADE;

CREATE SCHEMA tp1_qualite_nr;
SET SCHEMA 'tp1_qualite_nr';

CREATE TABLE gamenn (
  gameid INTEGER,
  gametitle VARCHAR(255),
  gamerelease DATE,
  compname VARCHAR(255),
  charname VARCHAR(255)
);

WbImport -type=text
-file='/home/etuinfo/lcaruhel/Documents/github/LorisFolder/Cours/BUT Info/S4/R4.03 - Qualité et au-delà du relationnel/TP/TP1/design_tp_games.csv'
-delimiter=';'
-table=tp1_qualite_nr.gamenn;
