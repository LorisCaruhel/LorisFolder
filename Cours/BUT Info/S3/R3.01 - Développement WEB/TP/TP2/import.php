<!DOCTYPE html>
<html lang="en">
   <head>
      <meta charset="UTF-8" />
      <meta name="viewport" content="width=device-width, initial-scale=1.0" />
      <title>Formulaire</title>
      <style>
        input, select {
            margin: 5px;
        }
      </style>
      <?php 
      require_once("functions.php"); 
      $data = importerData("INSEE.csv");
      ?>
   </head>
   <body>
    <?php if(!isset($_POST['nom'])) { ?>
      <form action="import.php" method="post" enctype="multipart/form-data">
            <label for="nom">Nom :</label>
            <input type="text" id="nom" name="nom" />
            <br />

            <label>Genre :</label>
            <input type="radio" id="genre1" name="genre" value="Homme" required />
            <label for="genre1">Homme</label>
            <input type="radio" id="genre2" name="genre" value="Femme" required />
            <label for="genre2">Femme</label>
            <br />
            
            <label for="classe">Classe :</label>
            <select id="classe" name="classe" required>
                <option value="6">6ème</option>
                <option value="5">5ème</option>
                <option value="4">4ème</option>
                <option value="3">3ème</option>
                <option value="seconde">Seconde</option>
                <option value="premiere">Première</option>
                <option value="terminal">Terminal</option>
            </select>
            <br />
            <input type="submit" value="Soumettre" />
      </form>
      <?php 
      
      $errorData = testerFormatData($data);

        ?>
        <pre>
            <?php print_r($errorData);?> 
        </pre>
        
    <?php } else {
        $nom = $_POST['nom'];
        $genre = $_POST['genre'];
        $classe = $_POST['classe'];
        

    } ?>
   </body>
</html>
