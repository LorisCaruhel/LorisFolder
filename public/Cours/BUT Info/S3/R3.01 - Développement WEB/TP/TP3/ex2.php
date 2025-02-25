<?php 
class Horodateur {
    public $label;
    public $maintenant;
    
    function __construct($lbl, $mtn = null) {
        $this->label = $lbl;
        $this->maintenant = $mtn ?? time();
    }

    function __destruct(){
        echo("Au revoir " . $this->label . " !<br>");
    }

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

    function estFutur($dt) {
        if($this->maintenant > $dt) {
            return true;
        }
        return false;
    }
}

$now = new Horodateur("Nom 1", 1664524330);
$now2 = new Horodateur("Nom 2", 2074751530);

?>