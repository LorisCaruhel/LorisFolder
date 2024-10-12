<?php

function testerNom($name) {
    $pattern = "/^(?!.*--.*--)[A-Za-z]+(?:['-]?[A-Za-z]+)*(?:--[A-Za-z]+)?(?:['-]?[A-Za-z]+)*$/";
    $name = strtoupper($name);

    if (preg_match($pattern, $name) && strlen($name) <= 40) {
        return true;
    } else {
        return false;
    }
}

function testerClasse($classe) {
    $classes = ["6", "5", "4", "3", "S", "P", "T"];
    $correct = in_array(strval($classe), $classes);

    return $correct;
}


function testerGenre($genre) {
    $genre = strtoupper(trim($genre));

    if ($genre == 'H' || $genre == 'F') {
        return true;
    }
    return false;
}

function testerPersonne($personneData) {
    if(testerNom($personne[0]) && testerGenre($personne[5]) && testerClasse($personne[4])) {
        $correct = true;
    }
    $correct = false;

    return $correct;
}

function importerData($nomFic) {
    $data = file($nomFic);
    $res = [];

    foreach($data as $key => $personne) {
        $dataExplode = explode(";", $personne);
        array_push($res, $dataExplode);
    }

    return $res;
}

function testerFormatData($data) {
    $errors = [];

    foreach($data as $key  => $personne) {
        if(!testerPersonne($personne)) {
           array_push($errors, $personne); 
        }
    }

    return $errors;
}