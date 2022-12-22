<?php
echo '<h1>getParameters page</h1>';

$sn1 = $_GET["balance"];

$text = "balance=" . $sn1;
$sum = $sn1;

echo $text;
echo "<br>";

$file1 = fopen("balance.txt","w") or die("Unable to open file!");
$text1 = "balance = %d$" . $sn1;

fwrite($file1, $text1);
fclose($file1);
?>