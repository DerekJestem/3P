<?php
    $text = "Kot biega po ogrodzie. Kot lubi bawić się w ogrodzie. W ogrodzie jest dużo miejsca dla kota.";
    $words = ["kot", "ogrodzie"];

    $finalText = str_ireplace($words, "<b>wyraz z tablicy</b>", $text);

    echo $finalText;