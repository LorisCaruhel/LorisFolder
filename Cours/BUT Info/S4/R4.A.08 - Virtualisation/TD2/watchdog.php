<?php

while(true) {
    $test = file_get_contents("http://localhost:1234");
    if(!$test) {
        echo "Erreur";
        sleep(5);
    }
}