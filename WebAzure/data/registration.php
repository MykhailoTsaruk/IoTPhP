<?php

require_once 'data.php';

    function load($data){
        foreach ($_POST as $key => $value){
            if (array_key_exists($key, $data)){
                $value = str_replace(" ", "", $value);
                $data[$key]['field_name'] = $value;
            }
        }
        return $data;
    }
    
    function write_to_file($file, $data){
        foreach($data as $key => $value){
            fwrite($file, $data[$key]['field_name']);
            fwrite($file, ";\n");
        }
    }

    $file = fopen("data.txt", "w");
    write_to_file($file, load($data));
    fclose($file);

    echo 'Successful registration';

?>