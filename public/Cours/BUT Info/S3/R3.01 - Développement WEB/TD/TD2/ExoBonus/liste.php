<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Fiches signalétiques</title>
    <?php
    include_once("functionsFicheSigna.php");
    $data = unserialize(file_get_contents("data"));
    ?>
</head>
<body>
    <div>
        <h1>Les données :</h1>
        <?php
        createTableau($data);
        ?>
    </div>
</body>
</html>