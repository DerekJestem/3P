<?php
    $dane = "Jan Kowalski, ul. Długa 23, 80-874 Gdańsk, tel. 693341678";
    $znak = ",";
    $ciag = strtok($dane, $znak);

    while (is_string($ciag)) {
        if ($ciag) {
            echo "$ciag<br>";
        }
        
        $ciag = strtok($znak);
    }
