<?php
    function writeData(){
        $file = fopen("sensor.txt", 'r') or die("error");
        $str = htmlentities(file_get_contents("sensor.txt"));
        echo $str;
        fclose($file);
    }
?>

<html>
<body>
<h1>HelloWorld</h1>
<?php writeData()?>
<meta http-equiv="Refresh" content="15" />
</body>
</html>