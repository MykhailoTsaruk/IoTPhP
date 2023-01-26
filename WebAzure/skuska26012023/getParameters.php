<?php

$sn1 = $_GET["temperature"];
$sn2 = $_GET["humidity"];

$text = "temperature = " . $sn1 . " °C" . " humidity = " . $sn2 . " %";

echo $text;

?>