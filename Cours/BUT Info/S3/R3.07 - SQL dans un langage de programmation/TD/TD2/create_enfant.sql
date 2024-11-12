DROP SCHEMA IF EXISTS enfantS CASCADE;
CREATE SCHEMA enfantS;
SET SCHEMA 'enfantS';

CREATE TABLE IF NOT EXISTS enfantS.enfant
(
   nopers  integer       NOT NULL,
   prenom  varchar(20)   NOT NULL,
   points  integer       NOT NULL,
   classe  varchar(10)   NOT NULL
);

ALTER TABLE enfantS.enfant
   ADD CONSTRAINT enfant_pk
   PRIMARY KEY (nopers);


INSERT INTO enfantS.enfant (nopers,prenom,points,classe) 
VALUES
  (1,'Jean',10,'CE2'),
  (3,'Alfred',15,'CE1_2'),
  (4,'Aline',9,'CE2_2'),
  (2,'Pierre',33,'CE1_2');

COMMIT;
