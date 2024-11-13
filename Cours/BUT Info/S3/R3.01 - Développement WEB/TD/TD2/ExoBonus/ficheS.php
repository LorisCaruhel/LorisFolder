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
    <style>
        input{
            margin: 5px;
        }
    </style>
</head>
<body>
    <form action="enreg.php" method="post" enctype="multipart/form-data">
        <label for="nom">Nom :</label>
        <input type="text" id="nom" name="nom" required/>
        <br />
        
        <label for="prenom">Prénom :</label>
        <input type="text" id="prenom" name="prenom"  required/>
        <br />

        <label for="email">Email :</label>
        <input type="email" id="email" name="email"  required/>
        <br />

        <label for="photo">Sélectionnez le fichier à utiliser</label>
        <input type="file" id="photo" name="photo" accept=".jpg, .webp, .png"  required/>
        <br />
        
        <input type="submit" value="Soumettre" />
    </form>
    <div>
        <?php
        if($data) {
            ?> <a href="liste.php">Listes des données</a> <?php
        }else {
            echo "Aucune données";
        }
        ?>
    </div>
</body>
</html>