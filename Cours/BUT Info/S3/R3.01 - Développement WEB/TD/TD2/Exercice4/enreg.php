<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Fiches signalétiques</title>
    <?php
    session_start();
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
            if(move_uploaded_file($tmpFile["tmp_name"], 'avatars/' . $nomfic . $suffix)) {
                if(!$_SESSION['data']) {
                    $_SESSION['data'] = [];
                }

                $data = &$_SESSION["data"];

                $data[$nomfic] = [
                    'nom' => $_POST['nom'],
                    'prenom' => $_POST['prenom'],
                    'email' => $_POST['email'],
                    'suffix' => $suffix
                ];
                $_SESSION['data'] = $data;
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
