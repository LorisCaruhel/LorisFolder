start transaction;

SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;
SHOW TRANSACTION ISOLATION LEVEL;

update enfantS.enfant set classe = 'CM1_1' where nopers = 1; -- Verrou RX

commit; -- Libérer verrou
