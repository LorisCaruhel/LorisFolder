CREATE TABLE ville(
    nom_v VARCHAR(50),
    nb_habitant INTEGER,
    nom_p VARCHAR(50) NOT NULL,
    CONSTRAINT VILLE_PK PRIMARY KEY(nom_v)
);

CREATE TABLE pays(
    nom_p VARHAR(50),
    superficie INTEGER,
    popul INTEGER,
    capacite VARCHAR(50),
    CONSTRAINT pays_pk PRIMARY KEY(nom_p),
    CONSTRAINT pays_uk PRIMARY KEY(capitale)
);

ALTER TABLE ville
    ADD CONSTRAINT ville_fk_pays
        FOREIGN KEY(nom_p) REFERENCES pays(nom_p);


ALTER TABLE pays
    ADD CONSTRAINT pays_pk_ville
        FOREIGN KEY(capitale) REFERENCES ville(nom_v);

-- Problème comme insérer des données 'France', 'Paris' par exemple ?
    -- Insérer un pays et une villes(sa capitale) et différer le vérification des 
    -- FK à la fin.