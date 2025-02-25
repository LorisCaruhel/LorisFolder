<?php
require_once __DIR__ . '/../models/user.php';

class UserController {
    private $db;

    public function __construct($db) {
        $this->db = $db;
    }

    public function addUser($_name, $_pseudo, $_email) {
        $user = new User($this->db);
        $stmt = $user->addUser($_name, $_pseudo, $_emai);
        
        return $stmt;
    }

    public function listUsers() {
        $user = new User($this->db);
        $stmt = $user->getAllUsers();

        return $stmt;
    }

    public function alterUser($_id, $_data) {
        $user = new User($this->db);
        $stmt = $user->alterUser($_id, $_data);

        return $stmt;
    }

    public function deleteUser($_id) {
        $user = new User($this->db);
        $stmt = $user->deleteUser($_id);

        return $stmt;
    }
}
?>