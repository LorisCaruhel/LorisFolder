<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Fiches signalétiques</title>
    <?php
    $uploads_dir = '/avatars';
    ?>
</head>
<body>
    <pre><?php print_r($_FILES); ?></pre>
    <pre><?php print_r($_POST); ?></pre>
    <?php
    $tmpFile = $_FILES["photo"];
    if($tmpFile && $tmpFile["error"] === 0) {
        $nomfic = time();
        $err = false;

        // Vérification du type de fichier
        if($tmpFile["type"] === "image/png") {
            $suffix = ".png";
        } else if($tmpFile["type"] === "image/jpg") { 
            $suffix = ".jpg";
        } else if($tmpFile["type"] === "image/webp") {
            $suffix = ".webp";
        } else {
            $suffix = null;
            $err = true;
        }

        if($suffix) {
            // Déplacement du fichier téléchargé
            if(move_uploaded_file($tmpFile["tmp_name"], 'avatars/' . $nomfic . $suffix)) {
                // Lecture des données existantes
                if(file_exists('data')) {
                    $sta = file_get_contents('data');
                    $data = unserialize($sta);
                } else {
                    $data = [];
                }

                // Vérification si les données existent déjà, sinon on les initialise
                if(!$data) {
                    $data = [];
                }

                // Ajout des nouvelles données
                $data[$nomfic] = [
                    'nom' => $_POST['nom'],
                    'prenom' => $_POST['prenom'],
                    'email' => $_POST['email'],
                    'suffix' => $suffix
                ];

                // Sauvegarde des données
                file_put_contents('data', serialize($data));
            } else {
                $err = true;
            }
        }

        if($err) {
            header('location:erreur.html');
        } else {
            header('location:sucess.html');
        }
    }
    ?>
</body>
</html>
