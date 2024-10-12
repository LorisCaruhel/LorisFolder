<?php
    include('connect_params.php');

    try {
        $dbh = new PDO("$driver:host=$server;dbname=$dbname", $user, $pass);
        $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $dbh->setAttribute(PDO::ATTR_DEFAULT_FETCH_MODE, PDO::FETCH_ASSOC);
        
        $q1 = "INSERT INTO distribill_s3._personnel (matr, nome, sal, datemb, comm, nodept)
                               VALUES (:matr, :nome, :sal, :datemb, :comm, :nodept)";
        $q2 = "DELETE FROM distribill_s3._employe WHERE matr = :matr";

        $tableau = array(
            "matr" => "9561",
            "nome" => "Nominoe",
            "sal" => "12",
            "datemb" => "1984-05-15",
            "comm" => "145",
            "nodept" => "22"
        );
    
        $dbh->beginTransaction();
        $stmt = $dbh->prepare($q2);
    
        $stmt->bindParam(':matr', $tableau['matr']);
        // $stmt->bindParam(':nome', $tableau['nome']);
        // $stmt->bindParam(':sal', $tableau['sal']);
        // $stmt->bindParam(':datemb', $tableau['datemb']);
        // $stmt->bindParam(':comm', $tableau['comm']);
        // $stmt->bindParam(':nodept', $tableau['nodept']);
    
        $stmt->execute();
    
        $dbh->commit();
    } catch (Exception $e) {
        $dbh->rollBack();
        echo "Failed: " . $e->getMessage();
    }

?>