<?php
require_once __DIR__ . '/../config/database.php';

class Trip {
    private $conn;
    private $table_name = "trips";
    public $id;
    public $titre;
    public $description;
    public $localisation;
    public $user_id;
    public $date_post;

    public function __construct($db) {
        $this->conn = $db;
    }

    public function addTrip($_titre, $_description, $_localisation, $_user_id) {
        $query = "INSERT INTO" . $this->table_name . " (titre, description, localisation, user_id) VALUES (:titre, :description, :localisation, :user_id)";
        $stmt = $this->conn->prepare($query);
        $stmt->bindParam(':titre', $_titre);
        $stmt->bindParam(':description', $_description);
        $stmt->bindParam(':localisation', $_localisation);
        $stmt->bindParam(':user_id', $_user_id);

        $stmt->execute();
    }

    public function getByUser($_user_id) {
        $query = "SELECT * FROM " . $this->table_name . " WHERE user_id = :id";
        $stmt = $this->conn->prepare($query);
        $stmt->bindParam(':id', $_user_id);

        $stmt->execute();

        return $stmt;
    }

    public function getAllTrips() {
        $query = "SELECT * FROM " . $this->table_name;
        $stmt = $this->conn->prepare($query);
        $stmt->execute();
        
        return $stmt;
    }

    public function alterTrip($_id, $_data) {
        try {
            $fields = [];
            foreach ($_data as $column => $value) {
                $fields[] = "$column = :$column";
            }
            
            $sql = "UPDATE trips SET " . implode(', ', $fields) . " WHERE id = :id";
            $stmt = $pdo->prepare($sql);
            
            $stmt->bindParam(':id', $_id, PDO::PARAM_INT);
    
            foreach ($_data as $column => $value) {
                $stmt->bindValue(":$column", $value);
            }
    
            $stmt->execute();
            echo "Mise à jour du trip réussie !";
        } catch (PDOException $e) {
            echo "Erreur : " . $e->getMessage();
        }
    }

    public function deleteTrip($_id) {
        $query = "DELETE FROM" . $this->table_name . " WHERE id = :id";
        $stmt = $this->conn->prepare($query);
        $stmt->bindParam(':id', $_id);

        $stmt->execute();
    }
}
?>