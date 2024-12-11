<?php
require_once __DIR__ . '/../models/trip.php';

class TripController {
    private $db;

    public function __construct($db) {
        $this->db = $db;
    }

    public function addTrip($_titre, $_description, $_localisation, $_user_id) {
        $trip = new trip($this->db);
        $stmt = $trip->addTrip($_titre, $_description, $_localisation, $_user_id);

        return $stmt;
    }

    public function getByUser($_user_id) {
        $trip = new Trip($this->db);
        $stmt = $trip->getByUser($_user_id);

        return $stmt;
    }

    public function listTrips() {
        $trip = new Trip($this->db);
        $stmt = $trip->getAllTrips();

        return $stmt;
    }

    public function alterTrip($_id, $_data) {
        $trip = new Trip($this->db);
        $stmt = $trip->alterTrip($_id, $_data);

        return $stmt;
    }

    public function deleteTrip($_id) {
        $trip = new Trip($this->db);
        $stmt = $trip->deleteTrip($_id);

        return $stmt;
    }
}
?>