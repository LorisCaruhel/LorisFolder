START TRANSACTION ;

UPDATE enfant SET points = points + 5 WHERE nopers = 1 ; -- RX

UPDATE enfant SET points = points + 9 WHERE nopers = 2 ; -- RX

COMMIT ;


-- U1 t1 START TRANSACTION ;
-- U2 t2 START TRANSACTION ;
-- U1 t3 UPDATE enfant SET points = points + 5 WHERE nopers = 1 ;
-- U2 t4 UPDATE enfant SET points = points + 7 WHERE nopers = 2 ;
-- U1 t5 UPDATE enfant SET points = points + 9 WHERE nopers = 2 ;
-- U2 t6 UPDATE enfant SET points = points + 11 WHERE nopers = 1 ;
-- U2 t7 COMMIT ;
-- U1 t8 COMMIT ;
-- Vrai odre des transactions : t1, t2, t3, t4, assassinat de U2, le relancer indépendament.
