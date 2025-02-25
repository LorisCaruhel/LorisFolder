<?php if (!empty($trips)) { ?>
    <table>
        <tr>
            <th>Code</th>
            <th>Titre</th>
            <th>Description</th>
            <th>Localisation</th>
            <th>User id</th>
            <th>Date post</th>
        </tr>
        
        <?php foreach ($trips as $trip) { ?>
        <tr>
            <td><?php echo htmlentities($trip['id']); ?></td>
            <td><?php echo htmlentities($trip['titre']); ?></td>
            <td><?php echo htmlentities($trip['description']); ?></td>
            <td><?php echo htmlentities($trip['localisation']); ?></td>
            <td><?php echo htmlentities($trip['user_id']); ?></td>
            <td><?php echo htmlentities($trip['date_post']); ?></td>
        </tr>
        <?php } ?>
    </table>
    <?php } else { ?>
        <p>Aucun trip</p>
<?php } ?>