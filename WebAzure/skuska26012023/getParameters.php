<?php

$sn1 = $_GET["temperature"];
$sn2 = $_GET["humidity"];

$text = "temperature = " . $sn1 . " °C" . " humidity = " . $sn2 . " %";

echo $text;
echo "<br>";

$file1 = fopen("sensor.txt","w") or die("Unable to open file!");
$text1 = "temperature = " . $sn1 . " °C" . " humidity = " . $sn2 . " %";

fwrite($file1, $text1);
fclose($file1);
?>