<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Boutique</title>
    <link rel="stylesheet" href="style.css">
    <?php
    require_once("init.php");
    $articleTab = file_get_contents("data");
    $articleTab = unserialize($articleTab);
    ?>
</head>
<body>
    <div>
        <h1>Liste d'article</h1>
    </div>
    <table>
        <thead>
            <tr>
                <th>Code</th>
                <th>Libellé</th>
                <th>Prix HT</th>
                <th>Taux TVA</th>
                <th>Montant TVA</th>
                <th>Prix TTC</th>
                <th>Stock</th>
                <th>Quantité vendue</th>
            </tr>
        </thead>
        <tbody>
        <?php
        $page = $_GET['page'];
        $nbArticle = ($page * 8) - 8;
        $articleTab = array_slice($articleTab, $nbArticle, 8);

        foreach($articleTab as $key => $article) {
            $code = $article[0];
            $libelle = $article[1];
            $prixHT = $article[2];
            $tauxTVA = $article[3];
            $montantTVA = ($tauxTVA * $prixHT)/100;
            $prixTTC = $prixHT + $montantTVA;
            $stock = $article[4];
            $vendu = $article[5];
            ?>

            <tr>
                <td style="text-align: center;"><?php echo $code ?></td>
                <td style="text-align: start;"><?php echo $libelle ?></td>
                <td style="text-align: end;"><?php echo $prixHT ?></td>
                <td style="text-align: end;"><?php echo $tauxTVA ?></td>
                <td style="text-align: end;"><?php echo $montantTVA ?></td>
                <td style="text-align: end;"><?php echo $prixTTC ?></td>
                <td style="text-align: center;"><?php echo $stock ?></td>
                <td style="text-align: center;"><?php echo $vendu ?></td>
            </tr>
            <?php
            $totaleHT = 0;
            $totaleStock = 0;
            $totaleTTCVendu = 0;
            $totaleVendu = 0;

            $totaleHT += $prixHT;
            $totaleStock += $stock;
            $totaleTTCVendu += $vendu * $prixTTC;
            $totaleVendu += $vendu;
        }
        ?>
        </tbody>
    </table>
    <?php
    if($page > 1) {
        ?>
        <a href="http://localhost:8888/liste.php?page=<?php echo $page-1;?>">
            <button class="button-55" role="button">Page précédente</button>
        </a>
        <?php
    }

    if($page < 3) {
        ?>
    <a href="http://localhost:8888/liste.php?page=<?php echo $page+1;?>">
        <button class="button-55" role="button">Page suivante</button>
    </a>
    <?php
    }?>
</body>
</html>