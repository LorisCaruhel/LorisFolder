VAR dotation REAL RELATION{
    quantite_dot INT, 
    no_fournisseur INT,
    no_client INT,
    no_projet INT
}KEY{no_fournisseur, no_client, no_projet};

CONSTRAINT dotation_fk_fournisseur
    dotation{no_fournisseur} <= fournisseur{no_fournisseur};
CONSTRAINT dotation_fk_article
    dotation{no_article} <= article{no_article};
CONSTRAINT dotation_fk_projet
    dotation{no_projet} <= projet{no_projet};

VAR nomenclature REAL RELATION{
    compose INT, 
    composant INT
}KEY{compose, composant};
CONSTRAINT nomenclature_fk_compose
    nomenclature{compose} <= article{no_article};
                            RENAME{no_article AS compose};
CONSTRAINT nomenclature_fk_composant
    nomenclature{composant} <= article{no_article};
                                RENAME{no_article AS composant};

CONSTRAINT compose_diff_coposant
    IS_EMPTY(
        nomenclature WHERE compose = composant
    );