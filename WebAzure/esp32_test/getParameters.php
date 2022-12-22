<?php
echo '<h1>getParameters page</h1>';

$sn1 = $_GET["balance"];

$text = "balance=" . $sn1;
$sum = $sn1;

echo $text;
echo "<br>";
echo "Sum:" . $sum;

$file1 = fopen("sensors.txt","w") or die("Unable to open file!");
$text1 = "a=" . $sn1;

fwrite($file1, $text1);
fclose($file1);
?>