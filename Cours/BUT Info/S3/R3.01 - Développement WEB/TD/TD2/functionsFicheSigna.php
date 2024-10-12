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
            ?>
            <tr>
                <td><?php echo $data[$key]["nom"] ?></td>
                <td><?php echo $data[$key]["prenom"] ?></td>
                <td><?php echo $data[$key]["email"] ?></td>
                <td><img src="./avatars/<?php echo $key ?>.png" alt="photo" width="150" height="150"></td>
            </tr>
            <?php
            }
            ?>
        </tbody>
    </table>
<?php
}