<?php
    $file = fopen("sensor.txt", 'r') or die("error");
    while(!feof($fd))
    {
        $str = htmlentities(fgets($file));
        echo $str;
    }
    fclose($file);
?>