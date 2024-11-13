CREATE TABLE centre(
    nom_centre VARCHAR(40) NOT NULL PRIMARY KEY,
    capacite_centre NUMERIC(5) NOT NULL, --INTEGER
    nom_pays VARCHAR(40) NOT NULL
);

CREATE TABLE stage(
    no_stage INTEGER NOT NULL,
    niv_stage VARCHAR(20) NOT NULL,
    nom_centre VARCHAR(40) NOT NULL,
    no_semaine INTEGER NOT NULL,
    cod_act VARCHAR(40) NOT NULL,
    CONSTRAINT stage_pk (PRIMARY KEY(no_stage));
);

ALTER TABLE stage
    ADD CONSTRAINT stage_fk_centre
        FOREIGN KEY (nom_centre)
        REFERENCES centre(nom_centre);

ALTER TABLE stage
    ADD CONSTRAINT stage_fk_semaine
        FOREIGN KEY (no_semaine)
        REFERENCES semaine(no_semaine);

ALTER TABLE stage
    ADD CONSTRAINT stage_fk_activite
        FOREIGN KEY (cod_act)
        REFERENCES activite(cod_act);

CREATE TABLE semaine(
    no_semaine INTEGER NOT NULL PRIMARY KEY
);

CREATE TABLE activite{
    cod_act VARCHAR(10) NOT NULL PRIMARY KEY,
    lib_act VARCHAR(10) NOT NULL
};

CREATE TABLE stage(
    no_stage INTEGER NOT NULL PRIMARY KEY,
    niveau_stage VARCHAR(10) NOT NULL,
    nom_centre VARCHAR(10) NOT NULL,
    no_semaine INTEGER NOT NULL,
    code_act VARCHAR(10)
);

CREATE TABLE encadre(
    nom_resp VARCHAR(10) NOT NULL,
    no_stage INTEGER NOT NULL PRIMARY KEY,
);

ALTER TABLE encadre
    ADD CONSTRAINT encadre_fk1
        FOREIGN KEY no_stage
        REFERENCES stage(no_stage);

CREATE TABLE client(
    no_client INTEGER NOT NULL PRIMARY KEY,
    nom VARCHAR(20) NOT NULL,
    prenom VARCHAR(20) NOT NULL,
    adresse VARCHAR(20) NOT NULL,
    code_postal VARCHAR(20) NOT NULL,
    ville VARCHAR(20) NOT NULL,
    tel_client VARCHAR(20) NOT NULL,
);

CREATE TABLE inscription(
    no_client INTEGER NOT NULL,
    no_stage INTEGER NOT NULL,
    date_inscription DATE NOT NULL DEFAULT currentdate(),
    CONSTRAINT inscription_pk PRIMARY KEY(no_stage, no_client),
    CONSTRAINT inscription_fk_stage
        FOREIGN KEY (no_stage) REFERENCES stage
    CONSTRAINT inscription_fk_client
        FOREIGN KEY  (nom_centre) REFERENCES centre
);

ALTER TABLE inscription(
    ADD CONSTRAINT inscription_fk
        FOREIGN KEY
);

VAR inscription BASE RELATION{
no_client INTEGER,
no_stage INTEGER,
date_inscription CHAR
}
KEY {no_client,no_stage};
CONSTRAINT inscription_fk1
inscription{no_client} =
client{no_client};
CONSTRAINT inscription_fk2
inscription{no_stage} <=
stage{no_stage};