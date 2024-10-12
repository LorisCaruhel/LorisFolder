
# STRUCTURE BDD


### creation d'une relation
```
var <nom_relation> BASE RELATION{
    <nom_attribut> <type>,
    <nom_attribut> <type>,
    <nom_attribut> <type>
}KEY{nom_cle};
```
### exemple

```
var ville BASE RELATION{
    NOM_V char,
    nb_habit int
}KEY{NOM_V};
```

### afficher une relation

```
<nom_relation>
```
### exemple
```
ville
```


## les differentes relations 

### 1  *
```
VAR <nom_relation> BASE RELATION {
	<cle1> <type>,
	<cle2> <type> 
} KEY {cle1} ;
CONSTRAINT <nom_contraint_relation> <nom_relation> {<cle1>} = <relation1> {<cle1>} ;
CONSTRAINT <nom_contraint_relatiob> <nom_relation> {<cle2>} <= <relation2> {<cle2>} ;
```
ne pas mettre de tiret '-' sinon marche pas 



### exemple
```
VAR se_situe BASE RELATION {
	NOM_V char,
	NOM_P char
} KEY {NOM_V} ;
CONSTRAINT se_situe_fk1 se_situe{NOM_V} = ville{NOM_V} ;
CONSTRAINT se_situe_fk2 se_situe {NOM_P} <= pays{NOM_V} ;
```

### 1  0..1
```
VAR <nom_relation> BASE RELATION {
	<cle1> <type>,
	<cle2> <type> 
} KEY {<cle1>} KEY{<cle2>};
CONSTRAINT <nom_contraint_relation> <nom_relation> {<cle1>} <= <relation1> {<cle1>} ;
```
### exemple 
```
VAR est_capitale BASE RELATION {
	NOM_V char,
	NOM_P char 
} KEY {NOM_V} KEY{NOM_P};
CONSTRAINT est_capitale_fk1 est_capitale {NOM_V} <= ville {NOM_V} ;
```

### 0..1 *

```
VAR <nom_relation> BASE RELATION {
	<cle1> <type>,
	<cle2> <type> 
} KEY {cle1} ;
CONSTRAINT <nom_contraint_relation> <nom_relation> {<cle1>} <= <relation1> {<cle1>} ;
CONSTRAINT <nom_contraint_relatiob> <nom_relation> {<cle2>} <= <relation2> {<cle2>} ;
```
### exemple

```
VAR se_situe BASE RELATION {
	NOM_V char,
	NOM_P char
} KEY {NOM_V} ;
CONSTRAINT se_situe_fk1 se_situe{NOM_V} <= ville{NOM_V} ;
CONSTRAINT se_situe_fk2 se_situe {NOM_P} <= pays{NOM_V} ;
```

### * *

```
VAR <nom_relation> BASE RELATION {
	<cle1> <type>,
	<cle2> <type> 
} KEY{cle1}KEY{cle2};
CONSTRAINT <nom_contraint_relation> <nom_relation> {<cle1>} <= <relation1> {<cle1>} ;
CONSTRAINT <nom_contraint_relatiob> <nom_relation> {<cle2>} <= <relation2> {<cle2>} ;
```
### exemple

```
VAR se_situe BASE RELATION {
	NOM_V char,
	NOM_P char
} KEY {NOM_V}KEY{NOM_P};
CONSTRAINT se_situe_fk1 se_situe{NOM_V} <= ville{NOM_V};
CONSTRAINT se_situe_fk2 se_situe {NOM_P} <= pays{NOM_V};
```





VAR baigne BASE RELATION {
	nomm char,
	nomp char
} KEY {nomm}KEY{nomp};
CONSTRAINT baigne_fk1_mer baigne {nomm} <= mer{nomm} ;
CONSTRAINT baigne_fk2_pays baigne {nomp} <= pays{nomp} ;