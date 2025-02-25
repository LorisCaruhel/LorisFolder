VAR candidat REAL RELATION{
    no_candidat INT,
    nom_cand CHAR,
    prenom_cand CHAR,
    adresse_cand CHAR,
    date_naissance CHAR,
    lib_formation CHAR
}KEY{no_candidat};
CONSTRAINT candidat_fk_formation
    candidat{lib_formation} <= formation{lib_formation};
VAR compose REAL RELATION{
    lib_formation CHAR,
    code_uv CHAR
}KEY{lib_formation, code_uv};
CONSTRAINT compose_fk_formation
    compose{lib_formation} <= formation; /* ou formation{lib_formation};*/
CONSTRAINT compose_fk_uv
    compose{code_uv} = uv{code_uv};

VAR enseigne REAL RELATION{
    lib_formation CHAR,
    code_uv CHAR,
    id_ens  INT
}KEY{lib_formation, code_uv, id_ens};
CONSTRAINT enseigne_fk_enseignant
    enseigne{id_ens} <= formation{id_ens};
CONSTRAINT enseignement_au_programme_fk
    enseigne{lib_formation, code_uv} <= compose;
/* Enseignement_au_programme est une clé étrangère de enseigne vers compose car composee a {lib_formation, code_uv}*/
/* Pas besoin d'exprimer les FK de enseigne vers formation et vers uv car elles sont réalisées par la composition de enseignement_au_programme_fk
et les FK compose_fk_formation et compose_fk_uv*/

VAR responsable REAL RELATION{
    lib_formation CHAR,
    code_uv CHAR,
    id_ens  INT
}KEY{lib_formation, code_uv};
CONSTRAINT responsable_des_matieres_que_j_enseigne
    responsable <= enseigne;

VAR notation REAL RELATION{
    no_candidat INT,
    lib_formation CHAR, 
    code_uv CHAR,
    note RATIONAL
}KEY{no_candidat, code_uv};
CONSTRAINT notation_fk_candidat
    notation{no_candidat} <= uv{code_uv};
CONSTRAINT notation_fk_formation
    notation{lib_formation} <= formation{lib_formation};
CONSTRAINT notation_dans_mes_uv
    notation{no_candidat, lib_formation, code_uv} <= candidat{no_candidat, lib_formation} JOIN compose; /* = Jointure */


