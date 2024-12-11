<pre>
<?php
require_once __DIR__ . '/../config/database.php';
require_once __DIR__ . '/../controllers/user_controller.php';
require_once __DIR__ . '/../controllers/trip_controller.php';

$database = new Database();
$db = $database->getConnection();

// Trips
$tripController = new TripController($db);
$stmt = $tripController->listTrips();
$trips = [];

while ($row1 = $stmt->fetch(PDO::FETCH_ASSOC)) {
    $trips[] = $row1;
}

// Users
$userController = new UserController($db);
$stmt = $userController->listUsers();
$users = [];
$tripsUser = [];

while ($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
    $users[] = $row;
    $tripUser[$row['id']] = $tripController->getByUser($row['id'])->fetchAll(PDO::FETCH_ASSOC);
}

// Les vues
require_once __DIR__ . '/../views/user_list.php';
require_once __DIR__ . '/../views/trip_list.php';
?>
</pre>