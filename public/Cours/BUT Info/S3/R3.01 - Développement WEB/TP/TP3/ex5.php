<pre>
<?php

class Coureur {
    public $prenom;
    public $nom;
    public $numero;

    private $abandon = false;

    public function __construct($_prenom, $_nom, $_numero) {
        $this->prenom = $_prenom;
        $this->nom = $_nom;
        $this->numero = $_numero;
    }

    public function abandonner() {
        $this->abandon = true;
    }

    public function getAbandon() {
        return $this->abandon;
    }
}

class Equipe {
    public $nom;
    public $coureurs = [];

    private $forfait = false;

    public function __construct($_nom) {
        $this->nom = $_nom;
    }

    public function ajouterCoureur($coureur) {
        $this->coureurs[] = $coureur;
    }

    static function creerEquipesAvecCourreur() {
        // Récupérer tous les fichiers dans le dossiers.
        $fichierEquipe = scandir('./TDF_2023');

        // Enlever les 3 premières lignes car dans le retour de scandir il y a . et .. et .DS_STORE.
        array_splice($fichierEquipe, 0, 3);


        $equipes = [];
        foreach($fichierEquipe as $key => $nomFichier) {
            $equipe = file("./TDF_2023/$nomFichier", FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);

            // Créer une instance d'équipe avec un nom d'équipe dynamique (equipe_1, equipe_2, ...)
            $nomEquipe = "equipe_$key";
            $$nomEquipe = new Equipe($equipe[0]);

            // Créer une cellule dans le tableau avec la clef (equipe_1, equipe_2)
            $equipes[$nomEquipe] = $$nomEquipe;

            // Récupérer que les courreurs (sans le nom d'équipe qui est en première ligne)
            $coureurs = array_slice($equipe, 1);
            foreach($coureurs as $key => $coureurData) {
                // Explode le nom d'un coureur pour avoir son numéro, nom, et prénom sépararé.
                $numNomCourreur = explode(" ", $coureurData, 3);

                $coureurInstance = new Coureur($numNomCourreur[1],   // Prenom
                                                $numNomCourreur[2], // Nom
                                                $numNomCourreur[0] // Numéro
                                            );
                $equipes[$nomEquipe]->ajouterCoureur($coureurInstance);
            }
        }

        return $equipes;
    }

    public function forfaiter() {
        foreach($this->coureurs as $key => $coureur) {
            $coureur->abandonner();
        }

        $this->forfait = true;
    }

    public function getForfait(){
        return $this->forfait;
    }
}

function creeTableauEquipe($equipe, $numEquipe) {
    ?>
    <style type="text/css">
        .tftable {
            font-size:12px;
            width:100%;
            border-width: 1px;
            border-color: #686767;
            border-collapse: collapse;
        }
        .tftable th {
            color:#fff;
            font-size:12px;
            background-color:#171515;
            border-width: 1px;
            padding: 8px;
            border-style: solid;
            border-color: #686767;
            text-align:center;
        }
        
        .tftable td {
            color:#000;
            font-size:12px;
            border-width: 1px;
            padding: 8px;
            border-style: solid;
            border-color: #686767;
        }
        .centrer {
            text-align: center;
        }
    </style>

    <table class="tftable">
        <tr>
            <th colspan="3"><?php echo $equipe->nom ?></th>
        </tr>
        <tr>
            <td rowspan="999" class="centrer" style="<?php echo ($equipe->getForfait() ? 'background-color:#f00;' : 'background-color:#fff;'); ?>"><?php echo $numEquipe ?></td>
        </tr>
        <?php
        foreach($equipe->coureurs as $key => $coureur) {
            ?>
            <tr style="<?php echo ($coureur->getAbandon() ? 'background-color:#f00;' : 'background-color:#fff;'); ?>">
                <td><?php echo $coureur->numero ?></td>
                <td><?php echo $coureur->nom . " " . $coureur->prenom ?></td>
            </tr>
            <?php
        }

        ?>
    </table>

    <?php
}

function trouveEquipe($nom) {
    global $equipes;

    foreach($equipes as $num => $equipe) {
        if($equipe->nom == $nom) {
            return $equipe;
        }
    } 
    return false;
}

function trouveDossard($num) {
    global $equipes;
    $trouve = [];

    foreach($equipes as $index => $equipe) {  
        foreach($equipe->coureurs as $numC => $coureur) {
            if($coureur->numero == $num) {  
                $trouve[$equipe->nom] = $coureur;  
                return $trouve;  
            }
        }
    }
    
    return false;  
}

function verifier($valeur) {
    if(!$valeur) {
        echo("Pas trouvé !\n");
    } else {
        print_r($valeur);
    }
}

$equipes = Equipe::creerEquipesAvecCourreur();
$equipeTrouve1 = trouveEquipe("COFIDIS");
$equipeTrouve2 = trouveEquipe("BILOUTE");

$coureurTrouve1 = trouveDossard(25);
$coureurTrouve2 = trouveDossard(3212);

verifier($equipeTrouve1);
verifier($equipeTrouve2);
verifier($coureurTrouve1);
verifier($coureurTrouve2);

foreach($equipes as $key => $equipeData) {
    creeTableauEquipe($equipeData, $key);
}


?>
</pre>

