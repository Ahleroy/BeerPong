<?php
$n=0;
echo "<form>";
for ($i=0; $i<12; $i++) {
    for ($j=0; $j<32; $j++) {
      echo "<input type=\"checkbox\" name=\""+$n+"\" value=\"1\">";
    //echo "<input type=\"checkbox\" name=\""+$n+"\" value=\""+$n+"\">";
    $n=$n+1;
  }
  echo "<br>";
}
echo "</form>";
?>
