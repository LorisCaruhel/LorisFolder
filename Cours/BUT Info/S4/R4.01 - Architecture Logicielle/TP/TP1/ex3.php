<pre>  
<?php

$url = "http://localhost:8081/v3.1/all?fields=name,alpha3Code,capital,cca3,flags";
if(!empty($_GET['name'])) {
    $url = "http://localhost:8081/v3.1/name/" . $_GET['name'] . "?fields=name,alpha3Code,capital,cca3,flags";
}
print_r($url);
$data = json_decode(file_get_contents($url));
?>
<style>
      table,th,td {
        padding: 10px;
        border: 1px solid black;
        border-collapse: collapse;
      }
</style>
<h1>Rechercher un pays</h1>
<form action="ex3.php" method="get" enctype="multipart/form-data">
  <label for="name">Nom du pays</label>
  <input type="text" name="name">

  <button type="submit">Rechercher</button>
</form>
<table>
    <thead>
        <th>Nom du pays</th>
        <th>Code pays</th>
        <th>Capitale</th>
    </thead>
    <tbody>
        <?php
            foreach($data as $key => $countrie) {
                $name = $countrie->name->common;
                $code = $countrie->cca3;
                $capitale = $countrie->capital[0];
                $img = $countrie->flags->png;
                ?>
                    <tr>
                        <td><?php echo isset($name) ? $name : "Inconnue"; ?></td>
                        <td><?php echo isset($code) ? $code : "Inconnue"; ?></td>
                        <td><?php echo isset($capitale) ? $capitale : "Inconnue"; ?></td>
                        <td><img src="<?php echo isset($img) ? $img : "Inconnue"; ?>" alt=""></td>
                    </tr>
                <?php
            }
        ?>
    </tbody>
</table>
</pre>