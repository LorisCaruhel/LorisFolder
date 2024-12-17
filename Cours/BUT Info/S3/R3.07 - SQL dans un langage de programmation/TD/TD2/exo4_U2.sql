START TRANSACTION ;

UPDATE enfantS.enfant SET points = points + 7 WHERE nopers = 2 ; -- RX

UPDATE enfantS.enfant SET points = points + 11 WHERE nopers = 1 ; -- RX

COMMIT ;
