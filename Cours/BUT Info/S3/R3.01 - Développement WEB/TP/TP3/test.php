<?php
class Etudiant_UR {
    private $nom;
    private $prenom;
    private $numero;

    function __set($nom_att, $val) {
        if ($nom_att === 'nom') {
            $this->nom = strtoupper($val); 
        } else if ($nom_att === 'prenom') {
            $this->prenom = substr($val, 0, 10); 
        } else if ($nom_att === 'numero') {
            $this->numero = $val;
        }
    }

    function __get($nom_att) {
        if ($nom_att === 'nom') {
            return $this->nom;
        } else if ($nom_att === 'prenom') {
            return $this->prenom;
        } 
    }
}
$etu = new Etudiant_UR();
$etu->nom = "l'asticot";
$etu->prenom = "LULU PAULO DELLA CASA BIANCA";
$etu->numero = 98765;

echo "$etu->nom $etu->prenom\n";
echo $etu->numero;