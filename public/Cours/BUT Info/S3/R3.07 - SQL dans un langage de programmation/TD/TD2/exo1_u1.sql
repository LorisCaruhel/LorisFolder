start transaction;

SET TRANSACTION ISOLATION LEVEL REPEATABLE READ;

select classe from enfantS.enfant where nopers = 1; -- Verrou AS

commit; -- Libérer verrou
