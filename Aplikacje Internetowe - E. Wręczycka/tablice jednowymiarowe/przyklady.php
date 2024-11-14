<?php
    function example($numer, $text) {
        echo "<h2>Przykład $numer</h2>\n";
        echo $text . "<br>\n<hr>\n";
    }

    function exarr($arr) {
        echo json_encode($arr) . '<br>';
    }

    function println($text) {
        echo $text . "<br>\n";
    }

    function br() {
        echo "<br>\n";
    }

    function hr() {
        echo "<hr>\n";
    }
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Zadania</title>
</head>
<body>
    <?php
        // PRZYKŁAD 6.9
        example('6.9', 'To jest symbol apostrofu \' użyty w kodzie PHP'); 


        // PRZYKŁAD 6.10
        $z = 'To jest tekst';
        example('6.10', $z);


        // PRZYKŁAD 6.11
        $x = "To jest tekst";
        example('6.11', $x);


        // PRZYKŁAD 6.12
        $napis = "napis";

        $tekst = <<< TX
            Tutaj rozpoczyna się $napis
        TX;
        example('6.12', $tekst);


        // PRZYKŁAD 6.13
        $imie = "Anna";
        $jezyk1 = "PHP";
        $jezyk2 = "JavaScript";
        $tekst = <<< TX
            Mam na imię $imie.
            Uczę się programować w języku $jezyk1.
            Umiem już programować w $jezyk2.
        TX;
        example('6.13', $tekst);


        // PRZYKŁAD 6.14
        $napis = "napis";
        $tekst = <<<'PC'
            Tutaj rozpoczyna się $napis
        PC;
        example('6.14', $tekst);


        // PRZYKŁAD x
        $tablica = array();
        $tablica = array(1, 2, 3, 4, 5, 6);
        $tablica = array("wpis 0", "wpis 1", "wpis 2"); 
        $tablica = array();
        $tablica[0] = 'wpis 0'; 
        $tablica[1] = 'wpis 1'; 
        $tablica[2] = 'wpis 2';
        
        exarr($tablica);

        println($tablica[2]);

        $tablica[] = "wpis kolejny";

        hr();
        
        $arr = [7, 3, 1, 6, 9, 5, 4, 10, 3, 2, 4, 3, 6, 12, 15, 4];
        for ($i=0; $i < count($arr); $i++) { 
           echo $arr[$i] . " "; 
        }

        br();

        foreach ($arr as $el) {
           echo $el . " "; 
        }
?>
</body>
</html>