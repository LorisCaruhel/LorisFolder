VAR client REAL RELATION{
    no_client INT,
    nom CHAR,
    prenom CHAR, 
    adresse1 CHAR,
    complement_adresse1 CHAR, 
    complement_adresse2 CHAR,
    code_postal CHAR,
    ville CHAR, 
    CA CHAR
}KEY{no_client};

VAR couleur REAL RELATION{
    couleurfl CHAR,
    designation
}KEY{couleurfl};

VAR fleur REAL RELATION{
    designation CHAR,
    prix_vente INT,
    couleurfl CHAR, 
    qte_stock INT
}KEY{designation, couleurfl};
CONSTRAINT fleur_fk_couleurfl
    fleur{couleurfl} <= couleur{couleurfl};
CONSTRAINT fleur_fk_qte_stock
    fleur{qte_stock} <= qte_stock{qte_stock};

VAR qte_stock REAL RELATION{
    couleurfl CHAR, 
    qte_stock INT, 
    designation CHAR
}KEY{couleurfl, designation};
CONSTRAINT qte_stock_fk_couleurfl
    qte_stock{couleurfl} <= couleur{couleurfl};
CONSTRAINT qte_stock_fk_fleur
    qte_stock{designation} <= fleur{designation};

VAR vente REAL RELATION{
    qte_achete INT,
    no_client INT, 
    no_vente INT,
    designation CHAR,
    couleurfl CHAR
}KEY{no_vente};
CONSTRAINT vente_fk_no_client
    vente{no_client} <= client{no_client};
CONSTRAINT vente_fk_designation
    vente{designation} <= fleur{designation};
CONSTRAINT vente_fk_couleur
    vente(couleurfl) <= couleur{couleurfl};
