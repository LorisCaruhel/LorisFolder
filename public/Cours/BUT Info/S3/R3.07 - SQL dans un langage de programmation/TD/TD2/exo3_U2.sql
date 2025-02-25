START TRANSACTION ;

SELECT points FROM enfantS.enfant WHERE nopers = 1 FOR UPDATE ; -- RS

UPDATE enfantS.enfant SET points = points + 5 WHERE nopers = 1 ; -- RX

COMMIT ;
