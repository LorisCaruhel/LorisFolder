<?php

function createTableau($data) {
    ?> 
    <table>
        <thead>
            <th>Nom</th>
            <th>Prénom</th>
            <th>Email</th>
            <th>Photo d'identité</th>
        </thead>
        <tbody>
            <?php 

            foreach($data as $key => $un_individu) {
                if(isset($_GET["key"])) {
                    unlink(`./avatars/"`.$key . $data[$key]["suffix"]);
                    unset($_SESSION["data"][$_GET["key"]]);
                    header("location:liste.php");
                }
            ?>
            <tr>
                <td><?php echo $data[$key]["nom"] ?></td>
                <td><?php echo $data[$key]["prenom"] ?></td>
                <td><?php echo $data[$key]["email"] ?></td>
                <td><img src="./avatars/<?php echo $key . $data[$key]["suffix"] ?>" alt="photo" width="150" height="150"></td>
                <td><a href="http://localhost:8888/liste.php?key=<?php echo $key ?>">Supprimer</a></td>
            </tr>
            <?php
            }
            ?>
        </tbody>
    </table>
<?php
}