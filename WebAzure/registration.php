<?php

    function load($data){
        foreach ($_POST as $title => $value){
            if (array_key_exists($title, $data)){
                $data[$title]['value'] = trim($value);
            }
        }
        return $data;
    }

    function write_to_file($file, $data){
        foreach($data as $title => $value){
            fwrite($file, "$title : $value;");
        }
    }

?>