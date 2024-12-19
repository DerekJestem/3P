<?php
    $dane = "Jan Kowalski, ul. Nowa 23, 80-874 Warszawa, tel. 693341678";

    echo "Ciąg główny: " . $dane . "<br>";
    
    $tel = strstr($dane, "tel.");

    if ($tel == false) {
        echo "Brak numeru telefonu";
    } else {
        echo "Znaleziony podciąg: " . $tel;
    }
    
