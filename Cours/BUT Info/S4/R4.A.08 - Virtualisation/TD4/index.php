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



?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        * {
            font-family: "Roboto Mono";
            font-size: 1.1em; 
            background-color: #323437;
            color: white;
        }
        body {
            text-align: center;
            display: flex;
            justify-content: center;
        }
        table {
            border-collapse: collapse;
        }
        td {
            border-bottom: white solid 1px;    
            padding: 30px;
        }
        thead { 
            border-bottom: white solid 2px;  
        }
    </style>
</head>
<body>
    <table>
        <thead>
            <th>id</th>
            <th>nom</th>
            <th>auteur</th>
            <th>total</th>
            <th>pret</th>
        </thead>
        <tbody>
        <?php
        $rows = $stmt->fetchAll();
        foreach($rows as $key => $row) {
            ?>
            <tr>
                <td><?php echo $row["id"] ?></td>
                <td><?php echo $row["nom"] ?></td>
                <td><?php echo $row["auteur"] ?></td>
                <td><?php echo $row["total"] ?></td>
                <td><?php echo $row["pret"] ?></td>
            </tr>
            <?php
        }
    ?>
    </tbody>
    </table>
</body>
</html>