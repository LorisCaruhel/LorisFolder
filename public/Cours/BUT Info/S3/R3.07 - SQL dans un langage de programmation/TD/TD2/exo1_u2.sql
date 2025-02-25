start transaction;

update enfantS.enfant set classe = 'CM1_1' where nopers = 1; -- Verrou RX

commit; -- Libérer verrou
