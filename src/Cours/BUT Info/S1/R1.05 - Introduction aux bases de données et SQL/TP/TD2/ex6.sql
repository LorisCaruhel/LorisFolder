/*L'association appartient est traduite pas une FK*/

VAR eleve REAL RELATION{
    no_eleve INT, 
    nom_eleve CHAR, 
    PRENOM_ELEVE CHAR, 
    code_classe INT
}KEY{no_eleve};
CONSTRAINT eleve_fk_appartient
    eleve{code_classe} <= classe{code_classe};

VAR delegue REAL RELATION{
    no_eleve INT, 
    code_classe INT
}KEY{no_eleve}KEY{code_classe};
CONSTRAINT delegue_fk_eleve
    delegue{no_eleve} <= eleve{no_eleve};
CONSTRAINT delegue_fk_code_classe
    delegue{code_classe} <= classe{code_classe};
CONSTRAINT delegue_de_ma_classe
    delegue <= eleve{no_eleve, code_classe};

VAR programme REAL RELATION{
    code_classe CHAR,  
    code_matiere CHAR,
    nb_heur INT
}KEY{code_classe, code_matiere};
CONSTRAINT programme_fk_matiere
    programme{code_matiere} <= matiere{code_matiere};
CONSTRAINT programme_fk_matiere
    programme{code_matiere} <= matiere{code_matiere};

VAR enseigne REAL RELATION{
    code_classe CHAR,
    code_matiere CHAR, 
    id_ens  INT
}KEY{code_classe, code_matiere};
CONSTRAINT enseigne_fk_classe
    enseigne{code_classe} <= classe{code_classe};
CONSTRAINT enseigne_fk_matiere
    enseigne{code_matiere} <= matiere{code_matiere};
CONSTRAINT enseigne_fk_enseignant
    enseigne{id_ens} <= enseignant{id_ens};
CONSTRAINT enseignement_au_programme
    enseigne{code_classe, code_matiere} <= programme{code_classe, code_matiere}; /* Clée étrangère */


/* La contrainte enseignement programme est aussi une clée étrangère car le couple {code_classe, code_matière}
est le clé de programme*/
/* Les contraintes de FK enseigne_fk_classe et enseigne_fk_matiere peuvent être "retirées" car elles 
sont redondantes avec la composition de la contrainte enseignement_au_progremme et des FK programme_fk_matiere*/