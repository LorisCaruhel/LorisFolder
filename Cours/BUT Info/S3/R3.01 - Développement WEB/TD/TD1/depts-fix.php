<?php
$depts = [
'01' => ['Ain', 'Bourg-en-Bresse'],
'02' => ['Aisne', 'Laon'],
'03' => ['Allier', 'Moulins'],
'04' => ['Alpes-de-Haute-Provence', 'Digne-les-Bains'],
'05' => ['Hautes-Alpes', 'Gap'],
'06' => ['Alpes-Maritimes', 'Nice'],
'07' => ['Ardèche', 'Privas'],
'08' => ['Ardennes', 'Charleville-Mézières'],
'09' => ['Ariège', 'Foix'],
'10' => ['Aube', 'Troyes'],
'11' => ['Aude', 'Carcassonne'],
'12' => ['Aveyron', 'Rodez'],
'13' => ['Bouches-du-Rhône', 'Marseille'],
'14' => ['Calvados', 'Caen'],
'15' => ['Cantal', 'Aurillac'],
'16' => ['Charente', 'Angoulême'],
'17' => ['Charente-Maritime', 'La Rochelle'],
'18' => ['Cher', 'Bourges'],
'19' => ['Corrèze', 'Tulle'],
'2A' => ['Corse-du-Sud', 'Ajaccio'],
'2B' => ['Haute-Corse', 'Bastia'],
'21' => ['Côte-d\'Or', 'Dijon'],
'22' => ['Côtes-d\'Armor', 'Saint-Brieuc'],
'23' => ['Creuse', 'Guéret'],
'24' => ['Dordogne', 'Périgueux'],
'25' => ['Doubs', 'Besançon'],
'26' => ['Drôme', 'Valence'],
'27' => ['Eure', 'Évreux'],
'28' => ['Eure-et-Loir', 'Chartres'],
'29' => ['Finistère', 'Quimper'],
'30' => ['Gard', 'Nîmes'],
'31' => ['Haute-Garonne', 'Toulouse'],
'32' => ['Gers', 'Auch'],
'33' => ['Gironde', 'Bordeaux'],
'34' => ['Hérault', 'Montpellier'],
'35' => ['Ille-et-Vilaine', 'Rennes'],
'36' => ['Indre', 'Châteauroux'],
'37' => ['Indre-et-Loire', 'Tours'],
'38' => ['Isère', 'Grenoble'],
'39' => ['Jura', 'Lons-le-Saunier'],
'40' => ['Landes', 'Mont-de-Marsan'],
'41' => ['Loir-et-Cher', 'Blois'],
'42' => ['Loire', 'Saint-Étienne'],
'43' => ['Haute-Loire', 'Le Puy-en-Velay'],
'44' => ['Loire-Atlantique', 'Nantes'],
'45' => ['Loiret', 'Orléans'],
'46' => ['Lot', 'Cahors'],
'47' => ['Lot-et-Garonne', 'Agen'],
'48' => ['Lozère', 'Mende'],
'49' => ['Maine-et-Loire', 'Angers'],
'50' => ['Manche', 'Saint-Lô'],
'51' => ['Marne', 'Châlons-en-Champagne'],
'52' => ['Haute-Marne', 'Chaumont'],
'53' => ['Mayenne', 'Laval'],
'54' => ['Meurthe-et-Moselle', 'Nancy'],
'55' => ['Meuse', 'Bar-le-Duc'],
'56' => ['Morbihan', 'Vannes'],
'57' => ['Moselle', 'Metz'],
'58' => ['Nièvre', 'Nevers'],
'59' => ['Nord', 'Lille'],
'60' => ['Oise', 'Beauvais'],
'61' => ['Orne', 'Alençon'],
'62' => ['Pas-de-Calais', 'Arras'],
'63' => ['Puy-de-Dôme', 'Clermont-Ferrand'],
'64' => ['Pyrénées-Atlantiques', 'Pau'],
'65' => ['Hautes-Pyrénées', 'Tarbes'],
'66' => ['Pyrénées-Orientales', 'Perpignan'],
'67' => ['Bas-Rhin', 'Strasbourg'],
'68' => ['Haut-Rhin', 'Colmar'],
'69' => ['Rhône', 'Lyon'],
'70' => ['Haute-Saône', 'Vesoul'],
'71' => ['Saône-et-Loire', 'Mâcon'],
'72' => ['Sarthe', 'Le Mans'],
'73' => ['Savoie', 'Chambéry'],
'74' => ['Haute-Savoie', 'Annecy'],
'75' => ['Paris', 'Paris'],
'76' => ['Seine-Maritime', 'Rouen'],
'77' => ['Seine-et-Marne', 'Melun'],
'78' => ['Yvelines', 'Versailles'],
'79' => ['Deux-Sèvres', 'Niort'],
'80' => ['Somme', 'Amiens'],
'81' => ['Tarn', 'Albi'],
'82' => ['Tarn-et-Garonne', 'Montauban'],
'83' => ['Var', 'Toulon'],
'84' => ['Vaucluse', 'Avignon'],
'85' => ['Vendée', 'La Roche-sur-Yon'],
'86' => ['Vienne', 'Poitiers'],
'87' => ['Haute-Vienne', 'Limoges'],
'88' => ['Vosges', 'Épinal'],
'89' => ['Yonne', 'Auxerre'],
'90' => ['Territoire de Belfort', 'Belfort'],
'91' => ['Essonne', 'Évry-Courcouronnes'],
'92' => ['Hauts-de-Seine', 'Nanterre'],
'93' => ['Seine-Saint-Denis', 'Bobigny'],
'94' => ['Val-de-Marne', 'Créteil'],
'95' => ['Val-d\'Oise', 'Cergy'],
];

require_once("regions.php");

function createTable($nomR) {
   global $regions;
   global $depts;

   $deptsNumR = $regions[$nomR];
   $deptsNomR = [];
   $deptsPrefecR = [];

   foreach ($deptsNumR as $numDept) {
      array_push($deptsNomR, $depts[$numDept][0]);
   }
   usort($deptsNomR, "cmpNomDept");
   
?>
   <table>
      <tr>
         <th rowspan='<?php echo count($depts) ?>'> <?php echo $nomR ?> </th>
      </tr>
      <?php
      $i = 0;
      foreach ($deptsNomR as $value) {
         $numeroCurrentDept = trouver_numDept($value);
         if($i%2 == 0) {
            ?>
            <tr class=enNoir>
               <td> <?php echo $value ?> </td>
               <td> <?php echo trouver_numDept($value) ?> </td>
               <td> <?php echo $depts[$numeroCurrentDept][1] ?> </td>
            </tr>

            <?php
         }else {
            ?>
            <tr>
               <td> <?php echo $value ?> </td>
               <td> <?php echo trouver_numDept($value) ?> </td>
               <td> <?php echo $depts[$numeroCurrentDept][1] ?> </td>
            </tr>
            <?php
         }
         ?>

         <?php
         $i++;
      }
      ?>
   </table>

<?php
   }

function cmpNomDept($a, $b)
{
   $currentNumDetpA = trouver_numDept($a);
   $currentNumDetpB = trouver_numDept($b);

   if (strlen($a) == strlen($b)) {
      return ($currentNumDetpA > $currentNumDetpB) ? -1 : 1;
   }
   return (strlen($a) > strlen($b)) ? -1 : 1;
}

function cmpNomReg($a, $b)
{
   global $regions;

   if (count($regions[$a]) == count($regions[$b])) {
      return (strlen($a) > strlen($b)) ? -1 : 1;
   }
   return (count($regions[$a]) < count($regions[$b])) ? -1 : 1;
}


function trouver_numDept($nomDept) {
   global $depts;

   $nomDeptTrouver = null;

   foreach($depts as $num => $value) {
      if($nomDept === $value[0]) {
         $nomDeptTrouver = $num;
      }
   }

   return $nomDeptTrouver;
}
   ?>

<!DOCTYPE html>
<html>
<head>
   <style>
      table{
         border-collapse: collapse;
      }
      
      th, td{
         border: 2px solid black;
         padding: 10px;
      }

      .enNoir {
         background-color:black;
         color:white;
      }
   </style>
</head>
<body>

   <pre>
   <?php
   // Trie des régions.
   uksort($regions, "cmpNomReg");

   // Créer un tableau pour chaques régions.
   foreach ($regions as $nomR => $deptsR) {
      createTable($nomR);
   }
   ?>
   </pre>
   
</body>
</html>
