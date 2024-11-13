<?php
require_once("regions.php");
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
    <ul>
        <pre>
            <?php 
                $page = $_GET['page'];
                $nbRegion = $page * 5; 
                $region = array_slice($regions, $nbRegion - 5, 5);
            foreach ($region as $nom => $depts) {
                ?> <li> <?php echo $nom ?> </li> <?php
            }
            ?>
        </pre>
    </ul>
    <?php
    if($page > 1) {
        ?>
        <a href="http://localhost:8888/exo3-region.php?page=<?php echo $page-1;?>">Page précédente</a>
        <?php
    }

    if($page < 3) {
        ?>
    <a href="http://localhost:8888/exo3-region.php?page=<?php echo $page+1;?>">Page suivante</a>
    <?php
    }?>
</body>
</html>