<?php
include('connect_params.php');
try {
    $q1 = "SELECT * FROM distribill_s3._dept";
    $q2 = "INSERT INTO distribill_s3._dept(nodept, nomdept, lieu) VALUES(:nodept, :nomdept, :lieu)";
    $q3 = "SELECT * FROM distribill_s3._personnel";
    $q4 = "UPDATE distribill_s3._personnel SET nome = 'BARBOTAUD' WHERE matr = '7369'";
    $q51 = "DELETE FROM distribill_s3._personnel WHERE matr = '7369'";
    $q52 = "DELETE FROM distribill_s3._employe WHERE matr = '7369'";


    $dbh = new PDO("$driver:host=$server;dbname=$dbname", $user, $pass);
    $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $dbh->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
    
    // Requête préparé :
    // $stmt = $dbh->prepare($q2);
    // $stmt->bindParam(':nodept', $nodept);
    // $stmt->bindParam(':nomdept', $nomdept);
    // $stmt->bindParam(':lieu', $lieu);

    // $nodept = 23;
    // $nomdept = "INFORMATIQUE";
    // $lieu = "St Brieuc";
    // $stmt->execute();

    $stmt = $dbh->query($q52);
    $stmt->execute();

    $stmt = $dbh->query($q51);
    $stmt->execute();

    // $countCountRow = $stmt->rowCount();
    // if($countCountRow == 0) {
    //     echo "Erreur : Auncune ligne affecté";
    // }

    $stmt = $dbh->query($q3);
    $stmt->execute();

    $result = $stmt->fetchAll();

    echo "<pre>";
    print_r($result);
    echo "</pre>";

    $dbh = null;
} catch (PDOException $e) {
    print "Erreur !: " . $e->getMessage() . "Code : " . $e->getCode() . "<br/>";
    die();
}
?>
