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
    $idL = $arg[0];
    $action = $arg[1];
    $nomL = $arg[2];
    $auteurL = $arg[3];
    $totalL = $arg[4];

    switch($action) {
        case "IN":
            $sql = "UPDATE biblio.livres SET pret = pret + :quantite WHERE id = :id";
            $stmt = $conn->prepare($sql);
            $stmt->execute(['quantite' => $totalL, 'id' => $idL]);
            echo "Livre bien prêté : ".$nomL."\n";
            break;

        case "OUT":
            $sql = "SELECT * FROM livres WHERE id = :id";
            $stmt = $conn->prepare($sql);
            $stmt->execute(['id' => $idL]);
            $rows = $stmt->fetch(PDO::FETCH_ASSOC);

            if($rows['pret'] > 0) {
                $sql = "UPDATE biblio.livres SET pret = pret - :quantite WHERE id = :id";
                $stmt = $conn->prepare($sql);
                $stmt->execute(['quantite' => $totalL, 'id' => $idL]);
                echo "Livre bien revenu : ".$nomL."\n";
            } else {
                echo "Livre veut revenir mais aucun prêt en cours : ".$nomL."\n";
            }
            break;

        case "ADD":
            $sql = "INSERT INTO biblio.livres(nom, auteur, total, pret) VALUES (:nom,:auteur,:total, 0)";
            $stmt = $conn->prepare($sql);   
            $stmt->execute(['nom' => $nomL, 'auteur' => $auteurL, 'total' => $totalL]);
            echo "Livre bien inséré : ".$nomL."\n";
            break;

        case "DEL":
            $sql = "SELECT * FROM livres WHERE id = :id";
            $stmt = $conn->prepare($sql);
            $stmt->execute(['id' => $idL]);
            $rows = $stmt->fetch(PDO::FETCH_ASSOC);
    
            if($rows['total'] > 0 && $rows['total'] >= $totalL) {
                echo "Suppression effectué : ".$nomL."\n";
                $sql = "DELETE FROM biblio.livres WHERE id = :id";
                $stmt = $conn->prepare($sql);
                $stmt->execute(['id' => $idL]);
                $rows = $stmt->fetch(PDO::FETCH_ASSOC);
            }else {
                echo "Erreur sur la quantité à supprimer : ".$nomL."\n";
            }
            break;

        default:
            echo "Erreur sur la commande : ".$nomL."\n";
            break;
    }
}