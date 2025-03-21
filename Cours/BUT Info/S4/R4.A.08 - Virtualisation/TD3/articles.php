<?php
$serveur = "td3_db";
$utilisateur = "toto";
$motDePasse = "lulu";
$baseDeDonnees = "td3";

try {
    $conn = new PDO("mysql:host=$serveur;dbname=$baseDeDonnees;charset=utf8", $utilisateur, $motDePasse);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $sql = "SELECT id, nom, prix, tva FROM articles";
    $stmt = $conn->prepare($sql);
    $stmt->execute();

    if ($stmt->rowCount() <= 0) {
        echo "Aucun résultat trouvé.";
    }
} catch (PDOException $e) {
    echo "Erreur de connexion : " . $e->getMessage();
}

$conn = null;
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
    <?php
    $rows = $stmt->fetchAll(PDO::FETCH_ASSOC);
    ?>
    <table>
        <thead>
            <th>id</th>
            <th>nom</th>
            <th>prix</th>
            <th>tva</th>
        </thead>
        <tbody>
        <?php
        foreach($rows as $key => $row) {
            ?>
            <tr>
                <td><?php echo $row["id"] ?></td>
                <td><?php echo $row["nom"] ?></td>
                <td><?php echo $row["prix"] ?></td>
                <td><?php echo $row["tva"] ?></td>
            </tr>
            <?php
        }
    ?>
    </tbody>
    </table>
</body>
</html>