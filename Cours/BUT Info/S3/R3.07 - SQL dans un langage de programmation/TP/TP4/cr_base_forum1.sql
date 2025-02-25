DROP SCHEMA IF EXISTS forum2 CASCADE;

CREATE SCHEMA forum2;
SET SCHEMA 'forum2';

CREATE TABLE forum2._user(
	nickname 	VARCHAR(30)	CONSTRAINT _user_pk PRIMARY KEY,
	pass 		VARCHAR(20)	NOT NULL,
	email 		VARCHAR(40)	NOT NULL
);
 
CREATE TABLE forum2._document (
	iddoc		SERIAL			CONSTRAINT _document_pk PRIMARY KEY, -- SERIAL pour auto-incrément
	content		VARCHAR(128) 	NOT NULL, 
	create_date	TIMESTAMP		NOT NULL DEFAULT now(), -- pas DATE, il faut etre precis
	author		VARCHAR(30)		NOT NULL,
	CONSTRAINT _document_fk_author
		FOREIGN KEY (author) REFERENCES forum2._user(nickname)
);

CREATE TABLE forum2._post(
	iddoc		INTEGER,
	CONSTRAINT _post_pk PRIMARY KEY (iddoc),
	CONSTRAINT _post_fk_inherit
		FOREIGN KEY (iddoc) REFERENCES forum2._document(iddoc) 
);

CREATE TABLE forum2._comment(
	iddoc		INTEGER,
	ref			INTEGER	NOT NULL,
	CONSTRAINT _comment_pk PRIMARY KEY (iddoc),
	CONSTRAINT _comment_fk_inherit
		FOREIGN KEY (iddoc) REFERENCES forum2._document(iddoc),
	CONSTRAINT _comment_fk_ref
		FOREIGN KEY (ref) REFERENCES forum2._document(iddoc),
	CONSTRAINT _comment_ck_iddoc_ref
		CHECK (iddoc <> ref)
);

---
--- Peuplement de la base
---

--- Premier utilisateur : virtuel, ne devrait pas pouvoir se connecter
INSERT INTO forum2._user VALUES ('Anonymous', 'VGilo6VKjhcv', 'null@nowhere.space');

--- Les autres
INSERT INTO forum2._user VALUES ('Félix', 'xilef', 'felix@gcris.fr');
INSERT INTO forum2._user VALUES ('Arthur', 'ruhtra', 'arthur@gcris.fr');
INSERT INTO forum2._user VALUES ('Jean', 'naej', 'jean@gcris.fr');
INSERT INTO forum2._user VALUES ('Thomas', 'samoht', 'thomas@gcris.fr');
INSERT INTO forum2._user VALUES ('Alex', 'xela', 'alex@gcris.fr');

--- Les posts et comments
--- Insister sur le fait qu'on ne doit pas creer de document en realite
--- Document ets une classe abstraite et on instancie un Post ou un Comment
--- Suite au prochain TP avec des vues post et comment et des triggers instead of

--- Les posts

INSERT INTO forum2._document(iddoc, content, author) VALUES (1, 'Bonjour tout le monde !', 'Félix');
INSERT INTO forum2._post(iddoc) VALUES (1);

INSERT INTO forum2._document(iddoc, content, author) VALUES (2, 'Quelqu''un jouera encore au foot cette année ?', 'Arthur');
INSERT INTO forum2._post(iddoc) VALUES (2);

--- Les comments
INSERT INTO forum2._document(iddoc, content, author) VALUES (3, 'Salut Félix ! Tu vas bien ?', 'Arthur');
INSERT INTO forum2._comment(iddoc, ref) VALUES (3,1);

INSERT INTO forum2._document(iddoc, content, author) VALUES (4, 'Oui, merci. Et toi ?', 'Félix');
INSERT INTO forum2._comment(iddoc, ref) VALUES (4,3);

INSERT INTO forum2._document(iddoc, content, author) VALUES (5, 'Tiens, Félix, tu es rentré de vacances ?', 'Jean');
INSERT INTO forum2._comment(iddoc, ref) VALUES (5,1);

INSERT INTO forum2._document(iddoc, content, author) VALUES (6, 'Bonjour Félix ! Bonjour à tous', 'Thomas');
INSERT INTO forum2._comment(iddoc, ref) VALUES (6,1);

INSERT INTO forum2._document(iddoc, content, author) VALUES (7, 'Salut Thomas !', 'Jean');
INSERT INTO forum2._comment(iddoc, ref) VALUES (7,6);

INSERT INTO forum2._document(iddoc, content, author) VALUES (8, 'Hello Thomas ! Tu reprends le foot cette année ?', 'Arthur');
INSERT INTO forum2._comment(iddoc, ref) VALUES (8,6);

INSERT INTO forum2._document(iddoc, content, author) VALUES (11, 'Non, je vais me mettre au handball, je crois.', 'Thomas');
INSERT INTO forum2._comment(iddoc, ref) VALUES (11,8);

INSERT INTO forum2._document(iddoc, content, author) VALUES (12, 'Ah ? Dommage, on s''amusait bien ensemble.', 'Félix');
INSERT INTO forum2._comment(iddoc, ref) VALUES (12,8);

INSERT INTO forum2._document(iddoc, content, author) VALUES (9, 'Oui, moi !', 'Jean');
INSERT INTO forum2._comment(iddoc, ref) VALUES (9,2);

INSERT INTO forum2._document(iddoc, content, author) VALUES (10, 'Pas moi.', 'Thomas');
INSERT INTO forum2._comment(iddoc, ref) VALUES (10,2);

INSERT INTO forum2._document(iddoc, content, author) VALUES (13, 'Moi aussi', 'Félix');
INSERT INTO forum2._comment(iddoc, ref) VALUES (13,2);

INSERT INTO forum2._document(iddoc, content, author) VALUES (14, 'Et moi !', 'Alex');
INSERT INTO forum2._comment(iddoc, ref) VALUES (14,2);

--
-- Pour mettre la sequence à la bonne valeur après les insertions
select setval('forum2._document_iddoc_seq', 14 );

/*
-- Autre façon : enchainer les insert
with insertion as (
INSERT INTO forum2._document(content, author) 
  VALUES ('Et moi !', 'Alex') RETURNING iddoc
)
insert into forum2._post select iddoc from insertion;

-- A condition de vérifier à chaque création qu'on commente le bon document
with insertion as (
INSERT INTO forum2._document(content, author) 
  VALUES ('Et moi aussi !', 'Arthur') RETURNING iddoc
)
insert into forum2._comment(iddoc,ref) select iddoc,6 from insertion;
*/

-- Fonctions pour les triggers.
CREATE OR REPLACE FUNCTION update_nickname()
RETURNS trigger
as 
$$
begin
  IF (OLD.nickname <> NEW.nickname) THEN
    raise exception 'Erreur, pas le droit de modifier le nickname %', OLD.nickname USING ERRCODE = '23000';
  ELSE
   UPDATE forum2._user
   SET pass = new.pass
   WHERE nickname = OLD.nickname;
   
   UPDATE forum2._user
   SET email = new.email
   WHERE nickname = OLD.nickname;
  END IF;
  RETURN NEW;
end;
$$
LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION delete_user()
RETURNS trigger
as 
$$
begin
    UPDATE forum2._document SET author='Anonymous' WHERE author=OLD.nickname;
    DELETE from forum2._user where nickname=OLD.nickname;
  RETURN NEW;
end;
$$
LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION insert_document()
RETURNS trigger
as 
$$
declare
  docid integer;
begin
  INSERT INTO forum2._document(content, author) VALUES(NEW.content, NEW.author) RETURNING iddoc INTO docid;
  INSERT INTO forum2._post(iddoc) VALUES(docid);
  RETURN NEW;
end;
$$
LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION update_post()
RETURNS trigger
as 
$$
begin
  IF OLD.author <> NEW.author THEN
    raise EXCEPTION 'Erreur, pas le droit de modifier le nickname %', OLD.author USING ERRCODE = '23000';
  ELSE
     UPDATE forum2._document SET content = NEW.content WHERE iddoc = NEW.iddoc;
  END IF;
  RETURN NEW;
end;
$$
LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION delete_post()
RETURNS trigger
as 
$$
begin
  WITH RECURSIVE ids AS (
    SELECT iddoc FROM forum2._document WHERE iddoc = OLD.iddoc
    UNION ALL
    SELECT c.iddoc 
    FROM _comment c 
    INNER JOIN ids i ON c.ref = i.iddoc
  ) DELETE FROM forum2._comment WHERE iddoc IN (
  SELECT iddoc FROM ids
  );
  DELETE FROM forum2._post WHERE iddoc = OLD.iddoc;
  DELETE FROM forum2._document WHERE iddoc = OLD.iddoc;
  
  RETURN NEW;
end;
$$
LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION insert_comment()
RETURNS trigger
as 
$$
declare
  docid integer;
begin
  INSERT INTO forum2._document(content, author) VALUES(NEW.content, NEW.author) RETURNING iddoc INTO docid;
  INSERT INTO forum2._comment(iddoc, ref) VALUES(docid, NEW.ref);

  RETURN NEW;
end;
$$
LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION update_comment()
RETURNS trigger
as 
$$
begin
  raise EXCEPTION 'Erreur, pas le droit de modifier cette table' USING ERRCODE = '23000';

  RETURN NEW;
end;
$$
LANGUAGE plpgsql;


CREATE OR REPLACE FUNCTION delete_comment()
RETURNS trigger
as 
$$
begin
  WITH RECURSIVE ids AS (
    SELECT iddoc FROM forum2._document WHERE iddoc = OLD.iddoc
    UNION ALL
    SELECT c.iddoc 
    FROM _comment c 
    INNER JOIN ids i ON c.ref = i.iddoc
  ) DELETE FROM forum2._comment WHERE iddoc IN (
  SELECT * FROM ids
  );
  DELETE FROM forum2._document WHERE iddoc = OLD.iddoc;

  RETURN NEW;
end;
$$
LANGUAGE plpgsql;


-- Création des vues.
CREATE OR REPLACE VIEW forum2.user AS
SELECT *
FROM forum2._user;

CREATE OR REPLACE VIEW forum2.post AS
SELECT DISTINCT *
FROM forum2._post
NATURAL JOIN forum2._document;

CREATE OR REPLACE VIEW forum2.comment AS
SELECT DISTINCT *
FROM forum2._comment;

-- TRIGGER sur l'update du nickname.
CREATE OR REPLACE TRIGGER tr_nickname
INSTEAD OF UPDATE 
ON forum2.user
FOR EACH ROW 
EXECUTE FUNCTION update_nickname();

-- TRIGGER sur la suppression d'un user.
CREATE OR REPLACE TRIGGER tr_delete_user
INSTEAD OF DELETE 
ON forum2.user
FOR EACH ROW 
EXECUTE FUNCTION delete_user();

-- TRIGGER sur l'insertion dans post.
CREATE OR REPLACE TRIGGER tr_inser_post
INSTEAD OF INSERT
ON forum2.post
FOR EACH ROW 
EXECUTE FUNCTION insert_document();

-- TRIGGER sur l'update d'un post.
CREATE OR REPLACE TRIGGER tr_update_post
INSTEAD OF UPDATE
ON forum2.post
FOR EACH ROW 
EXECUTE FUNCTION update_post();

-- TRIGGER sur l'update d'un post.
CREATE OR REPLACE TRIGGER tr_delete_post
INSTEAD OF DELETE
ON forum2.post
FOR EACH ROW 
EXECUTE FUNCTION delete_post();

-- TRIGGER sur l'insert d'un comment.
CREATE OR REPLACE TRIGGER insert_comment
INSTEAD OF INSERT
ON forum2.comment
FOR EACH ROW 
EXECUTE FUNCTION insert_comment();

-- TRIGGER sur l'update d'un comment.
CREATE OR REPLACE TRIGGER tr_update_comment
INSTEAD OF UPDATE
ON forum2.comment
FOR EACH ROW 
EXECUTE FUNCTION update_comment();

-- TRIGGER sur le delete d'un comment.
CREATE OR REPLACE TRIGGER tr_delete_comment
INSTEAD OF DELETE
ON forum2.comment
FOR EACH ROW 
EXECUTE FUNCTION delete_comment();


CREATE OR REPLACE VIEW document_exclusion 
AS
    SELECT iddoc
    FROM _post intersesct 
         SELECT iddoc 
         FROM _comment;

  

CREATE OR REPLACE VIEW document_totalite 
AS
  SELECT iddoc
  FROM _document 
  (
    SELECT iddoc 
    FROM _post 
    UNION 
    SELECT iddoc 
    FROM _comment
  );

CREATE OR REPLACE FUNCTION ftg_document_partition() RETURNS TRIGGER AS $$
BEGIN
  -- Exclusion
  PERFORM * FROM document_exclusion;
  IF FOUND THEN
    RAISE EXCEPTION 'L''exclusion entre _post et _comment n''est pas respectée';
  END IF;
  -- Totalisé
  PERFORM * FROM document_totalite;
  if FOUND then 
    RAISE EXECEPTION 'La totalité sur _document n''est pas respectée';
  END IF;
  RETURN NULL; -- Après ça plus rien n'est possible ;)
END;
$$ language plpgsql;

DROP TRIGGER IF EXISTS tg_document_partition ON _document;
CREATE CONSTRAINT TRIGGER tg_document_partition
  AFTER INSESRT ON _DOCUMENT
  DEFERRABLE INITIALLY DEFEREED
  FOR EACH ROW
  EXECUTE FUNCTION ftg_document_partition();
  

START TRANSACTION;
WITH nouvel_id AS (
  INSERT INTO _document (content, author)
  VALUES ('Test1 : doc sans post ni comment', 'Alex')
  RETURNING iddoc
  )
  INSERT INTO _post (iddoc)
    SELECT iddoc FROM nouvel_id;
  COMMIT;
 
SELECT * from forum1._document
ORDER BY iddoc ASC;

SELECT * FROM _post;
  
