<?php 

$data = file("articles");
$stock = 0;
$vendu = 0;
    
$articleTab = [];
foreach($data as $key => $article) {
    $currentTab = explode(',', $article);
    array_push($currentTab, $stock);
    array_push($currentTab, $vendu);
    
    array_push($articleTab, $currentTab);
}

file_put_contents("data", serialize($articleTab));
?>