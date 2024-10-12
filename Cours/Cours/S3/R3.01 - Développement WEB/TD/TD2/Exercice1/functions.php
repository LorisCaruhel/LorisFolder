<?php
require_once("regions.php"); 

function createTableRegion($nomR) {
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

function createTableDepartement($nomD) {
   global $depts;

   $deptTrouve = [];
   foreach($depts as $key => $dept) {
      $nomDeptClean = trim($dept[0]);

      if(strstr(strtoupper($dept[0]), strtoupper($nomD))) {
         $deptTrouve[$key] = $dept;
      }
   }

   ?>
   <table>
      <?php
      $i = 0;
      foreach ($deptTrouve as $key => $dept) {
         if($i%2 == 0) {
            ?>
            <tr class=enNoir>
               <td> <?php echo $key ?> </td>
               <td> <?php echo $dept[0] ?> </td>
               <td> <?php echo $dept[1] ?> </td>
            </tr>
            
            <?php
         }else {
            ?>
            <tr>
               <td> <?php echo $key ?> </td>
               <td> <?php echo $dept[0] ?> </td>
               <td> <?php echo $dept[1] ?> </td>
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

   $numDeptTrouver = null;

   foreach($depts as $num => $value) {
      if($nomDept === $value[0]) {
         $numDeptTrouver = $num;
      }
   }

   return $numDeptTrouver;
}


function trouverRegion($nomD) {
   global $depts;

   $numRegTrouver = null;

   foreach($depts as $num => $value) {
      if($nomDept === $value[0]) {
         $numRegTrouver = $num;
      }
   }

   return $numRegTrouver;
}

?>