<?php 
require_once("regions.php"); 
include_once("functions.php");
?>
<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Formulaire</title>
    <style>
        body {
            font-family: Calibri, Candara, Segoe, Segoe UI, Optima, Arial, sans-serif;
        }
        
        input, label, select {
            padding: 5px;
            margin: 5px;
        }
        
        table{
            border-collapse: collapse;
        }
        
        th, td{
            border: 2px solid black;
            padding: 10px;
            width: 175px;
        }
        
        .enNoir {
            background-color:black;
            color:white;
        }
        
        /* CSS */
        .button-30 {
            align-items: center;
            appearance: none;
            background-color: #FCFCFD;
            border-radius: 4px;
            border-width: 0;
            box-shadow: rgba(45, 35, 66, 0.4) 0 2px 4px,rgba(45, 35, 66, 0.3) 0 7px 13px -3px,#D6D6E7 0 -3px 0 inset;
            box-sizing: border-box;
            color: #36395A;
            cursor: pointer;
            display: inline-flex;
            font-family: "JetBrains Mono",monospace;
            height: 48px;
            justify-content: center;
            line-height: 1;
            list-style: none;
            overflow: hidden;
            padding-left: 16px;
            padding-right: 16px;
            position: relative;
            text-align: left;
            text-decoration: none;
            transition: box-shadow .15s,transform .15s;
            user-select: none;
            -webkit-user-select: none;
            touch-action: manipulation;
            white-space: nowrap;
            will-change: box-shadow,transform;
            font-size: 18px;
            margin: 10px;
        }
        
        .button-30:focus {
            box-shadow: #D6D6E7 0 0 0 1.5px inset, rgba(45, 35, 66, 0.4) 0 2px 4px, rgba(45, 35, 66, 0.3) 0 7px 13px -3px, #D6D6E7 0 -3px 0 inset;
        }
        
        .button-30:hover {
            box-shadow: rgba(45, 35, 66, 0.4) 0 4px 8px, rgba(45, 35, 66, 0.3) 0 7px 13px -3px, #D6D6E7 0 -3px 0 inset;
            transform: translateY(-2px);
        }
        
        .button-30:active {
            box-shadow: #D6D6E7 0 3px 7px inset;
            transform: translateY(2px);
        }
    </style>
    <?php
    $nomR = $_GET['nomR'];
    $nomDept = $_GET['nomDept'];
    ?>
</head>
<body>
    <a href="form-reg.php"><button class="button-30" role="button">Retour</button></a>
    <?php
    if ($nomR !== "" && $nomDept === "") {
        createTableRegion($nomR);
    } else if ($nomR === "" && $nomDept !== "") {
        createTableDepartement($nomDept);
    } else if ($nomR === "" && $nomDept === "") {
        foreach ($depts as $numDept => $value) {
            ?>
            <table>
                <tr>
                    <td> <?php echo $numDept ?> </td>
                    <td> <?php echo $value[0] ?> </td>
                    <td> <?php echo $depts[$numDept][1] ?> </td>
                </tr>
            </table>
            <?php
            }
    } else {
        
        createTableDepartement($nomDept);
    }

    ?>
    </body>
    </html>