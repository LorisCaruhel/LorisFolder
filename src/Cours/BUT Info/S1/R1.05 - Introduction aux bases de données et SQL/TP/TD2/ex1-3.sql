VAR ville REAL RELATION{
    nom_v CHAR, 
    nb_habit INT,
    nom_p CHAR
}KEY{nom_v};
CONSTRAINT nom_p_fk_pays
    ville{nom_p} <= pays{nom_p};


VAR pays REAL RELATION{
    nom_p CHAR,
    superficie INT,
    popul INT,
    nom_v CHAR
}KEY{nom_p};
CONSTRAINT nom_v_fk_ville
    pays{nom_v} <= capitale{nom_v};

VAR capitale REAL RELATION{
    nom_v CHAR,
    nom_p CHAR
}KEY{nom_v, nom_p};
CONSTRAINT nom_p_fk_capitale
    capitale{nom_p} <= pays{nom_p};
CONSTRAINT nom_v_fk_capitale
    capitale{nom_v} <= ville{nom_v};
    
