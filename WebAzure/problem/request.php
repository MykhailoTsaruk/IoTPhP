<?php

    $file = fopen('problem.txt', 'w');
    fwrite($file, $_POST["problem-message"]);
    echo "Your request has been sent.";

?>