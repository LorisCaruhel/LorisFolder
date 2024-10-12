
VAR pays REAL RELATION{
     nomp CHAR, 
     superficie INT,
     pop INT
}KEY{nomp};


VAR mer REAL RELATION{
     nomm CHAR, 
     surface INT
}KEY{nomm};


VAR ville REAL RELATION{
     nomv CHAR,
     nomp CHAR
}KEY{nomv};
CONSTRAINT ville_fk_se_situe
     ville{nomp} <= pays{nomp};


VAR fleuve REAL RELATION{
     nomf CHAR, 
     longueur INT,
     nomm CHAR
}KEY{nomf};
CONSTRAINT fleuve_fk_se_jette
     fleuve{nomm} <= mer{nomm};


VAR traverse REAL RELATION{
     nomf CHAR, 
     nomp CHAR
}KEY{nomf, nomp};
CONSTRAINT traverse_fk_pays
     traverse{nomp} <= pays{nomp};
CONSTRAINT traverse_fk_fleuve
     traverse{nomf} = fleuve{nomf}; /*Pour respecter ceci lors de l'insert il faut faire un insert, un autre insert (ne pas rajouter un fleuve sans rajouté de pays)*/


VAR arrose REAL RELATION{
     nomf CHAR, 
     nomv CHAR
}KEY{nomf, nomv};
CONSTRAINT arrose_fk_fleuve
     arrose{nomf} <= fleuve{nomf};
CONSTRAINT arrose_fk_ville
     arrose{nomv} <= ville{nomv};


VAR baigne REAL RELATION{
     nomp CHAR, 
     nomm CHAR
}KEY{nomp, nomm};
CONSTRAINT baigne_fk_pays
     baigne{nomp} <= pays{nomp};
CONSTRAINT baigne_fk_mer
     baigne{nomm} <= mer{nomm};



pays := RELATION { TUPLE { nomp "Danemark",superficie 43,pop 5627 },
	TUPLE { nomp "Pays Bas",superficie 41,pop 16357 },
	TUPLE { nomp "France",superficie 640,pop 66000 },
	TUPLE { nomp "Allemagne",superficie 357,pop 80767 },
	TUPLE { nomp "Espagne",superficie 504,pop 46163 },
	TUPLE { nomp "Italie",superficie 301,pop 60782 },
	TUPLE { nomp "Luxembourg",superficie 2,pop 524 },
	TUPLE { nomp "Belgique",superficie 30,pop 11203 } };

mer := RELATION { TUPLE { nomm "Mer du Nord",surface 750 },
	TUPLE { nomm "Atlantique",surface 106400 },
	TUPLE { nomm "Mediterranee",surface 2500 },
	TUPLE { nomm "Manche",surface 6 },
	TUPLE { nomm "Baltique",surface 415 },
	TUPLE { nomm "Mer Rouge",surface 438 },
	TUPLE { nomm "Mer d'Oman",surface 3600 },
	TUPLE { nomm "Mer Noire",surface 436 } };

ville := RELATION { TUPLE { nomp "Allemagne",nomv "Berlin" },
	TUPLE { nomp "Allemagne",nomv "Bonn" },
	TUPLE { nomp "Allemagne",nomv "Cologne" },
	TUPLE { nomp "Allemagne",nomv "Dusseldorf" },
	TUPLE { nomp "Allemagne",nomv "Hambourg" },
	TUPLE { nomp "Allemagne",nomv "Magdebourg" },
	TUPLE { nomp "Belgique",nomv "Liege" },
	TUPLE { nomp "Belgique",nomv "Namur" },
	TUPLE { nomp "France",nomv "Besançon" },
	TUPLE { nomp "France",nomv "Le Havre" },
	TUPLE { nomp "France",nomv "Lyon" },
	TUPLE { nomp "France",nomv "Nantes" },
	TUPLE { nomp "France",nomv "Paris" },
	TUPLE { nomp "France",nomv "Rouen" },
	TUPLE { nomp "France",nomv "Sedan" },
	TUPLE { nomp "France",nomv "Strasbourg" },
	TUPLE { nomp "France",nomv "Verdun" },
	TUPLE { nomp "Pays Bas",nomv "Maastricht" },
	TUPLE { nomp "Pays Bas",nomv "Rotterdam" },
	TUPLE { nomp "Pays Bas",nomv "Utrecht" } };

baigne := RELATION { TUPLE { nomp "Danemark",nomm "Mer du Nord" },
	TUPLE { nomp "Pays Bas",nomm "Mer du Nord" },
	TUPLE { nomp "France",nomm "Mer du Nord" },
	TUPLE { nomp "Allemagne",nomm "Mer du Nord" },
	TUPLE { nomp "Espagne",nomm "Atlantique" },
	TUPLE { nomp "France",nomm "Atlantique" },
	TUPLE { nomp "Italie",nomm "Mediterranee" },
	TUPLE { nomp "Espagne",nomm "Mediterranee" },
	TUPLE { nomp "France",nomm "Mediterranee" },
	TUPLE { nomp "France",nomm "Manche" },
	TUPLE { nomp "Danemark",nomm "Baltique" },
	TUPLE { nomp "Allemagne",nomm "Baltique" } };

fleuve := RELATION { TUPLE { nomm "Mer du Nord",nomf "Elbe",longueur 1091 },
	TUPLE { nomm "Atlantique",nomf "Loire",longueur 1012 },
	TUPLE { nomm "Mer du Nord",nomf "Meuse",longueur 950 },
	TUPLE { nomm "Mer du Nord",nomf "Rhin",longueur 1350 },
	TUPLE { nomm "Mediterranee",nomf "Rhône",longueur 812 },
	TUPLE { nomm "Manche",nomf "Seine",longueur 776 } }
,
traverse := RELATION { TUPLE { nomf "Seine",nomp "France" },
	TUPLE { nomf "Elbe",nomp "Allemagne" },
	TUPLE { nomf "Loire",nomp "France" },
	TUPLE { nomf "Meuse",nomp "Pays Bas" },
	TUPLE { nomf "Meuse",nomp "France" },
	TUPLE { nomf "Rhin",nomp "Allemagne" },
	TUPLE { nomf "Rhin",nomp "France" },
	TUPLE { nomf "Rhin",nomp "Pays Bas" },
	TUPLE { nomf "Rhône",nomp "France" } };


arrose := RELATION { TUPLE { nomf "Seine",nomv "Le Havre" },
	TUPLE { nomf "Seine",nomv "Rouen" },
	TUPLE { nomf "Seine",nomv "Paris" },
	TUPLE { nomf "Elbe",nomv "Hambourg" },
	TUPLE { nomf "Elbe",nomv "Magdebourg" },
	TUPLE { nomf "Loire",nomv "Nantes" },
	TUPLE { nomf "Meuse",nomv "Maastricht" },
	TUPLE { nomf "Meuse",nomv "Rotterdam" },
	TUPLE { nomf "Meuse",nomv "Sedan" },
	TUPLE { nomf "Meuse",nomv "Verdun" },
	TUPLE { nomf "Meuse",nomv "Liege" },
	TUPLE { nomf "Meuse",nomv "Namur" },
	TUPLE { nomf "Rhin",nomv "Utrecht" },
	TUPLE { nomf "Rhin",nomv "Rotterdam" },
	TUPLE { nomf "Rhin",nomv "Dusseldorf" },
	TUPLE { nomf "Rhin",nomv "Cologne" },
	TUPLE { nomf "Rhin",nomv "Bonn" },
	TUPLE { nomf "Rhin",nomv "Strasbourg" },
	TUPLE { nomf "Rhône",nomv "Lyon" } };


/* 
TP2 :

1)  INSERT fleuve
	    RELATION { TUPLE { nomm "Atlantique",nomf "La Garonne",longueur 529 }},
	INSERT traverse
		RELATION { TUPLE { nomf "La Garonne",nomp "France" }};

2) DELETE ville 
	WHERE nomv = "Nantes",

	DELETE arrose 
	WHERE nomv = "Nantes";

3)
Allemagne	357	80767
Belgique	30	11203
Danemark	43	5627
Espagne	504	46163
France	640	66000
Italie	301	60782
Luxembourg	2	524
Pays Bas	41	16357


4)
Elbe	1091	Mer du Nord
La Garonne	529	Atlantique
Loire	1012	Atlantique
Meuse	950	Mer du Nord
Rhin	1350	Mer du Nord
Rhône	812	Mediterranee
Seine	776	Manche

5) pays WHERE pop > 30000

6) fleuve WHERE longueur < 1000

7) fleuve{nomf}

8) (fleuve WHERE longueur < 1000){nomf}

9) ((traverse WHERE nomp = "France") UNION (traverse WHERE nomp = "Allemagne")){nomf}

10) (traverse WHERE nomp = "France"){nomf} INTERSECT (traverse WHERE nomp = "Allemagne"){nomf}

11) arrose{nomv}

12) ville{nomv} MINUS arrose{nomv}


TP2 bis :

1) pays{nomp} WHERE traverse{nomf} <> 'Rhin'

2) (
		traverse
		WHERE nomf <> "Rhin"
	){nomp}

3) pays{nomp} 
	MINUS 
	(traverse WHERE nomf = "Rhin"){nomp}

4) traverse{nomp} 
MINUS 
(traverse WHERE nomf = "Rhin"){nomp}

5)traverse{nomp}
MINUS 
(traverse WHERE nomf <> "Rhin"){nomp}

6) 
*/