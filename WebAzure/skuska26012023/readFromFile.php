<?php
    $file = fopen("sensor.txt", 'r') or die("error");
    $str = htmlentities(file_get_contents("sensor.txt"));
    echo $str;
    fclose($file);
?>