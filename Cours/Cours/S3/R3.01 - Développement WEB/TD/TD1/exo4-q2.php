<?php
$data = file_get_contents("data");
?>

<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <meta http-equiv="Content-Language" content="fr" />
    <meta name="author"/>
    <title>
        Départements
    </title>
</head>
<body>
    <pre>
    <?php 

    $newArtiste = [
        "Artiste" => "Christine and the Queens",
        "Album" => "Chaleur Humaine",
        "Ventes" => 850000  
    ];

    $data = unserialize($data);
    $data[2014] = $newArtiste;
    $data = serialize($data);   
    file_put_contents("data new", $data);

    echo "data serialisé = " . $data . "\n";
    echo "\ndata non serialisé = ";
    print_r(unserialize($data));

    ?>
    </pre>
</body>
</html>