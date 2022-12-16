<?php
echo '<h1>getParameters page</h1>';

$sn1 = $_GET["a"];
$sn2 = $_GET["b"];

$text = "a=" . $sn1 . " b=" . $sn2;
$sum = $sn1 + $sn2;

echo $text;
echo "<br>";
echo "Sum:" . $sum;

$file1 = fopen("sensors.txt","w") or die("Unable to open file!");
$text1 = "a=" . $sn1 . " b=" . $sn2;

fwrite($file1, $text1);
fclose($file1);
?>