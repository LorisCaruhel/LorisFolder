start transaction;

SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
SHOW TRANSACTION ISOLATION LEVEL;

select classe from enfantS.enfant where nopers = 1; -- Verrou AS

commit; -- Libérer verrou
