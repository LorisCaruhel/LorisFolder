<?php
require_once("serial.php");
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
    
    echo "variable 1 non serialisé = " . $ser_var1;
    echo "\tvariable 1 serialisé = " . serialize($ser_var1) . "\n";

    echo "variable 2 non serialisé = " . $ser_var2;
    echo "\tvariable 2 serialisé = " . serialize($ser_var2) . "\n";

    echo "variable 3 non serialisé = " . $ser_var3;
    echo "\t\tvariable 3 serialisé = " . serialize($ser_var3) . "\n";

    echo "variable 4 non serialisé = " . $ser_var4;
    echo "\tvariable 4 serialisé = " . serialize($ser_var4) . "\n";

    echo "variable 5 non serialisé = " . $ser_var5;
    echo "\tvariable 5 serialisé = " . serialize($ser_var5) . "\n";

    ?>
    </pre>
</body>
</html>