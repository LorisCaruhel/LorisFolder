<?php
require_once __DIR__ . '/../config/database.php';

class User {
    private $conn;
    private $table_name = "users";
    public $id;
    public $name;
    public $pseudo;
    public $email;

    public function __construct($db) {
        $this->conn = $db;
    }

    public function addUser($_name, $_pseudo, $_email) {
        $query = "INSERT INTO" . $this->table_name . " (name, pseudo, email) VALUES (:name, :pseudo, :email)";
        $stmt = $this->conn->prepare($query);
        $stmt->bindParam(':name', $_name);
        $stmt->bindParam(':pseudo', $_pseudo);
        $stmt->bindParam(':email', $_email);

        $stmt->execute();
    }

    public function getAllUsers() {
        $query = "SELECT id, name, email, pseudo FROM " . $this->table_name;
        $stmt = $this->conn->prepare($query);

        $stmt->execute();

        return $stmt;
    }

    public function alterUser($_id, $_data) {
        try {
            $fields = [];
            foreach ($data as $column => $value) {
                $fields[] = "$column = :$column";
            }
            
            $sql = "UPDATE users SET " . implode(', ', $fields) . " WHERE id = :id";
            $stmt = $pdo->prepare($sql);
            
            $stmt->bindParam(':id', $_id, PDO::PARAM_INT);
    
            foreach ($data as $column => $value) {
                $stmt->bindValue(":$column", $value);
            }
    
            $stmt->execute();
            echo "Mise à jour de l'utilisateur réussie !";
        } catch (PDOException $e) {
            echo "Erreur : " . $e->getMessage();
        }
    }

    public function deleteUser($_id) {
        $query = "DELETE FROM" . $this->table_name . " WHERE id = :id";
        $stmt = $this->conn->prepare($query);
        $stmt->bindParam(':id', $_id);

        $stmt->execute();
    }
}
?>