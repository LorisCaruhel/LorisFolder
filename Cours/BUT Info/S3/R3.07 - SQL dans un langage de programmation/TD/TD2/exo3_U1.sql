START TRANSACTION ;

SELECT points FROM enfantS.enfant WHERE nopers = 1 FOR UPDATE ; -- RS

UPDATE enfantS.enfant SET points = points + 8 WHERE nopers = 1 ; -- RX

COMMIT ;


-- U1 t1 START TRANSACTION ;
-- U2 t2 START TRANSACTION ;
-- U1 t3 SELECT points FROM enfant WHERE nopers = 1 FOR UPDATE ;
-- U2 t4 SELECT points FROM enfant WHERE nopers = 1 FOR UPDATE ;
-- U2 t5 UPDATE enfant SET points = points + 5 WHERE nopers = 1 ;
-- U1 t6 UPDATE enfant SET points = points + 8 WHERE nopers = 1 ;
-- U2 t7 COMMIT ;
-- U1 t8 COMMIT ;

-- Vrai odre des transactions : t1, t2, t3, t6(+8), t8, t4, t5(+5), t7
