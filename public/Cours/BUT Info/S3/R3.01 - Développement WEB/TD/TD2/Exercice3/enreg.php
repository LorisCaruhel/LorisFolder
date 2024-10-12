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

    <?php
    $tmpFile = $_FILES["photo"];
    if($tmpFile && $tmpFile["error"] === 0) {
        $nomfic = time();
        $err = false;
        if($tmpFile["type"] === "image/png") {
            $suffix = ".png";
        }else if($tmpFile["type"] === "image/jpg") {
            $suffix = ".jpg";
        }else if($tmpFile["type"] === "image/webp") {
            $suffix = ".webp";
        }else {
            $suffix = null;
            $err = True;
        }
        if($suffix) {
            if(move_uploaded_file($tmpFile["tmp_name"], 'avatars/' . $nomfic . $suffix)) {
                $sta = file_get_contents('data');
                $data = unserialize($sta);
                if($data) {
                    $data = [];
                }
                $data[$nomfic] = [
                    'nom' => $_POST['nom'],
                    'prenom' => $_POST['prenom'],
                    'email' => $_POST['email'],
                    'suffix' => $suffix
                ];
                file_put_contents('data', serialize($data));
            }else {
                $err = True;
            }
        }

        if($err) {
            echo "Erreur";
        }else {
            header('location:ficheS.php');
        }
    }
    move_uploaded_file($tpmFile, $uploads_dir . $_FILES["photo"]["name"]);
    ?>
</body>
</html>