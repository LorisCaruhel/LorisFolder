<?php
$serveur = "biblio_db";
$utilisateur = "root";
$motDePasse = "admin";
$baseDeDonnees = "biblio";

try {
    $conn = new PDO("mysql:host=$serveur;dbname=$baseDeDonnees;charset=utf8", $utilisateur, $motDePasse);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $sql = "SELECT * FROM livres";
    $stmt = $conn->prepare($sql);
    $stmt->execute();

    if ($stmt->rowCount() <= 0) {
        echo "Aucun résultat trouvé.";
    }
} catch (PDOException $e) {
    echo "Erreur de connexion : " . $e->getMessage();
}


$data = file_get_contents("./mvt");
$data = explode("\n", $data);
$commandes = [];
foreach($data as $key => $command) {
    array_push($commandes, explode(":", $command));
    
}

foreach($commandes as $key => $arg) {
    if($arg[1] === "IN") {
        $sql = "UPDATE biblio.livres SET pret = pret + {$arg[4]} WHERE id = {$arg[0]}";
        $stmt = $conn->prepare($sql);
        $stmt->execute();
        echo "Livre bien prêté\n";
    } else if($arg[1] === "OUT") {
        $sql = "SELECT * FROM livres WHERE id = {$arg[0]}";
        $stmt = $conn->prepare($sql);
        $stmt->execute();
        $rows = $stmt->fetch(PDO::FETCH_ASSOC);
        if($rows['pret'] > 0) {
            $sql = "UPDATE biblio.livres SET pret = pret - {$arg[4]} WHERE id = {$arg[0]}";
            $stmt = $conn->prepare($sql);
            $stmt->execute();
            echo "Livre bien revenu\n";
        } else {
            echo "Livre veut revenir mais aucun prêt en cours\n";
        }
    } else if($arg[1] === "ADD") {
        $sql = "INSERT INTO biblio.livres(nom, auteur, total, pret) VALUES ($arg[2], $arg[3], $arg[4], 0)";
        $stmt = $conn->prepare($sql);
        $stmt->execute();
        echo "Livre bien inséré";
    } else if($arg[1] === "DEL") {
        $sql = "SELECT * FROM livres WHERE id = {$arg[0]}";
        $stmt = $conn->prepare($sql);
        $stmt->execute();
        $rows = $stmt->fetch(PDO::FETCH_ASSOC);

        if($rows['total'] > $arg[4] && $arg[4] > 0) {
            
        } else if($arg[4] < 0) {

        } else {

        }
    } else {
        echo "Erreur sur la commande";
    }
}