START TRANSACTION;

ALTER TABLE enfantS.enfant ADD COLUMN nom VARCHAR(20); -- AX

UPDATE enfantS.enfant SET nom = 'Dupont' WHERE nopers = 1; -- RX

ROLLBACK;

-- U1 t1 START TRANSACTION ;
-- U2 t2 START TRANSACTION ;
-- U1 t3 ALTER TABLE enfant ADD COLUMN nom VARCHAR(20);
-- U2 t4 LOCK TABLE enfant IN EXCLUSIVE MODE ;
-- U2 t5 DROP TABLE enfant;
-- U1 t6 UPDATE enfant SET nom = 'Dupont' WHERE nopers = 1 ;
-- U2 t7 ROLLBACK ;
-- U1 t8 ROLLBACK ;
-- Vrai ordre de transaction : t1, t2, t3, t6, t8, t4, t5, t7
