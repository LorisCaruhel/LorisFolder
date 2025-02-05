<!doctype html>
<html lang="fr">
<?php

$url = "http://localhost:8081/v3.1/all?fields=name,alpha3Code,capital,cca3,flags";
if(!empty($_GET['name'])) {
    $url = "http://localhost:8081/v3.1/name/" . $_GET['name'] . "?fields=name,alpha3Code,capital,cca3,flags";
} else if(!empty($_GET['lang'])) {
    $url = "http://localhost:8081/v2/lang/" . $_GET['lang'] . "?fields=name,alpha3Code,capital,cca3,flags";
} else  if(!empty($_GET['devise'])) {
    $url = "http://localhost:8081/v3.1/currency/" . $_GET['devise']  . "?fields=name,alpha3Code,capital,cca3,flags";
}
if(isset($_GET['page'])) {
    $page = $_GET['page'];
} else {
    $_GET['page'] = 1;
    $page = 1;
}

$data = json_decode(file_get_contents($url));
?>
<head>
  <meta charset="utf-8">
  <title>Pays recherche</title>
  <link rel="stylesheet" href="style.css">
  <script src="script.js"></script>

<style>
      table,th,td {
        padding: 10px;
        border: 1px solid black;
        border-collapse: collapse;
      }
      .drapeau{
        width: 75px;
        height: 50px;
      }
      input {
        width: 300px;
      }
      .erreur {
        color:red;
      }
      .pagination {
        display: flex;
        margin: 10px;
      }
      .pagination a {
        text-decoration: none;
        color: black;
      }
      form {
        display: flex;
        flex-direction: column;
        margin: 10px;
        padding: 10px;
      }
      button {
        width: 100px;
        height: 30px;
      }
</style>
</head>
<body>
    <h1>Rechercher un pays</h1>
    <form action="pays.php" method="get" enctype="multipart/form-data">
        <label for="name">Nom du pays</label>
        <input type="text" name="name">

        <label for="lang">Langue</label>
        <input type="text" name="lang" placeholder="Mettre le code de la langue (fr par exemple)">

        <label for="devise">Devise</label>
        <input type="text" name="devise" placeholder="Mettre le code de la devise (eur par exemple)">

        <button type="submit">Rechercher</button>
    </form>
    <div class="pagination">
    <?php
    $page = isset($_GET['page']) && is_numeric($_GET['page']) ? (int)$_GET['page'] : 1;
    $previousPage = max(1, $page - 1);
    $nextPage = $page + 1;
    
    // En prendre 10.
    $data = array_slice($data, ($_GET['page']*10)-10, 10);

    $parametre = $_GET;
    $parametre['page'] = $previousPage;
    $urlAvant = "http://localhost:8888/pays.php?" . http_build_query($parametre);

    $parametre['page'] = $nextPage;
    $urlApres = "http://localhost:8888/pays.php?" . http_build_query($parametre);
    ?>

    <button <?php if ($page <= 1) echo 'disabled'; ?>>
        <a href="<?php echo $urlAvant; ?>">Précédente</a>
    </button>
    <button <?php if (count($data) < 10) echo 'disabled'; ?>>
        <a href="<?php echo $urlApres; ?>">Suivante</a>
    </button>

    </div>
    <table>
        <thead>
            <th>Nom du pays</th>
            <th>Code pays</th>
            <th>Capitale</th>
        </thead>
        <tbody>
            <?php
                foreach($data as $key => $countrie) {
                    if(!empty($_GET['name'])) {
                        $name = $countrie->name->common;
                        $code = $countrie->cca3;
                        $capitale = $countrie->capital[0];
                        $img = $countrie->flags->png;
                        ?>
                            <tr>
                                <td><?php echo isset($name) ? $name : "Inconnue"; ?></td>
                                <td><?php echo isset($code) ? $code : "Inconnue"; ?></td>
                                <td><?php echo isset($capitale) ? $capitale : "Inconnue"; ?></td>
                                <td><img class="drapeau" src="<?php echo isset($img) ? $img : "Inconnue"; ?>" alt=""></td>
                            </tr>
                        <?php
                    } else if(!empty($_GET['lang'])) {
                        $name = $countrie->name;
                        $code = $countrie->alpha3Code;
                        $capitale = $countrie->capital;
                        $img = $countrie->flags->png;
                        ?>
                            <tr>
                                <td><?php echo isset($name) ? $name : "Inconnue"; ?></td>
                                <td><?php echo isset($code) ? $code : "Inconnue"; ?></td>
                                <td><?php echo isset($capitale) ? $capitale : "Inconnue"; ?></td>
                                <td><img class="drapeau" src="<?php echo isset($img) ? $img : "Inconnue"; ?>" alt=""></td>
                            </tr>
                        <?php
                    } else if(!empty($_GET['devise'])) {
                        $name = $countrie->name->common;
                        $code = $countrie->cca3;
                        $capitale = $countrie->capital[0];
                        $img = $countrie->flags->png;
                        ?>
                            <tr>
                                <td><?php echo isset($name) ? $name : "Inconnue"; ?></td>
                                <td><?php echo isset($code) ? $code : "Inconnue"; ?></td>
                                <td><?php echo isset($capitale) ? $capitale : "Inconnue"; ?></td>
                                <td><img class="drapeau" src="<?php echo isset($img) ? $img : "Inconnue"; ?>" alt=""></td>
                            </tr>
                        <?php
                    }else {
                        $name = $countrie->name->common;
                        $code = $countrie->cca3;
                        $capitale = $countrie->capital[0];
                        $img = $countrie->flags->png;
                        ?>
                            <tr>
                                <td><?php echo isset($name) ? $name : "Inconnue"; ?></td>
                                <td><?php echo isset($code) ? $code : "Inconnue"; ?></td>
                                <td><?php echo isset($capitale) ? $capitale : "Inconnue"; ?></td>
                                <td><img class="drapeau" src="<?php echo isset($img) ? $img : "Inconnue"; ?>" alt=""></td>
                            </tr>
                        <?php
                    }
                }
            ?>
        </tbody>
    </table>
</body>
</html>