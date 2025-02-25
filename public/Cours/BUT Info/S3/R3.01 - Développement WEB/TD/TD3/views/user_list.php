<?php if (!empty($users)) { ?>
    <table>
        <tr>
            <th>Code</th>
            <th>Nom</th>
            <th>Email</th>
            <th>Pseudo</th>
            <th>Ses voyages</th>
        </tr>
        
        <?php foreach ($users as $user) { ?>
        <tr>
            <td><?php echo htmlentities($user['id']); ?></td>
            <td><?php echo htmlentities($user['name']); ?></td>
            <td><?php echo htmlentities($user['email']); ?></td>
            <td><?php echo htmlentities($user['pseudo']); ?></td>
            <td><a href="?user_id=<?php echo urlencode($user['id']); ?>">Ses voyages</a></td> 
        </tr>
        <?php } ?>
    </table>
<?php } else { ?>
    <p>Aucun utilisateur</p>
<?php } ?>

<?php
if (!empty($_GET['user_id'])) {
    $user_id = intval($_GET['user_id']);
    
    $tripUser = $tripController->getByUser($user_id)->fetchAll(PDO::FETCH_ASSOC);
    
    if (!empty($tripUser)) {
        echo "<h2>Voyages de l'utilisateur " . htmlentities($user_id) . "</h2>";
        ?>
        <table>
        <tr>
            <th>Code</th>
            <th>Titre</th>
            <th>Description</th>
            <th>Localisation</th>
            <th>User id</th>
            <th>Date post</th>
        </tr>
        
        <?php
         foreach ($tripUser as $trip) {?>
            <tr>
                <td><?php echo htmlentities($trip['id']); ?></td>
                <td><?php echo htmlentities($trip['titre']); ?></td>
                <td><?php echo htmlentities($trip['description']); ?></td>
                <td><?php echo htmlentities($trip['localisation']); ?></td>
                <td><?php echo htmlentities($trip['user_id']); ?></td>
                <td><?php echo htmlentities($trip['date_post']); ?></td>
            </tr>
        <?php } ?>
    </table><?php
    } else {
        echo "<p>Aucun voyage pour cet utilisateur.</p>";
    }
}
?>
