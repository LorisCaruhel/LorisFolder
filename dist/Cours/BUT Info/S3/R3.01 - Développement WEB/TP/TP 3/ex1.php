<?php 
class Horodateur {
    public $label;
    public $maintenant;

    function setNow() {
        $this->maintenant = time();
    }

    function fmtDate() {
        return date("Y-m-d", $this->maintenant);
    }

    function fmtHeure() {
        return date("H:i:s", $this->maintenant);
    }

    function difference($dt) {
        if($this->maintenant > $dt) {
            return $this->maintenant - $dt;
        } else {
            return $dt - $this->maintenant;
        }
    }
}

$now = new Horodateur();
$now2 = new Horodateur();

$now->setNow();
$now2-> setNow();

$now->label = "Premier objet";
$now2->label = "Deuxième objet";

echo "Objet créé le " . $now->fmtDate() . " à " . $now->fmtHeure() . "<br>";
echo "La différence entre maintenant et un autre time est :  " . $now->difference(1664524330) . "<br>";
echo "La différence entre maintenant et un autre time est :  " . $now->difference(2074751530) . "<br>";

?>