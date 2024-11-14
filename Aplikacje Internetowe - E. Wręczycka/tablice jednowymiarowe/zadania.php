<?php
    function ex($numer, $text) {
        echo "<h2>Zadanie $numer</h2>\n";
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

    function h2($text) {
        echo "<h2>$text</h2>\n";
    }
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Zadania</title>
    <style>
        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }

        html {
            font-family: system-ui, -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;
        }

        main {
            width: 100%;
            height: 100vh;
            background-color: whitesmoke;
            display: flex;
            justify-content: center;
            align-items: center;
        }

        main .container {
            background-color: white;
            padding: 25px;
            border-radius: 15px;
            box-shadow:
            0.9px 0.9px 1.4px rgba(0, 0, 0, 0.02),
            2.4px 2.4px 3.5px rgba(0, 0, 0, 0.028),
            4.8px 4.8px 6.5px rgba(0, 0, 0, 0.035),
            8.8px 8.8px 11.6px rgba(0, 0, 0, 0.042),
            15.7px 15.7px 21.7px rgba(0, 0, 0, 0.05),
            27px 27px 52px rgba(0, 0, 0, 0.07);
        }

        h2 {
            margin-bottom: 5px;
        }

        hr {
            margin: 15px 0 25px 0;
        }
    </style>
</head>
<body>
    <main>
        <div class="container">
            <?php
                $arr = [7, 3, 1, 6, 9, 5, 4, 10, 3, 2, 4, 3, 6, 12, 15, 4];

                // ZADANIE 1
                h2("Zadanie 1");
                println("Pętla for:");

                for ($i=0; $i < count($arr); $i++) { 
                    echo $arr[$i] . " "; 
                }
        
                br();
                println("Pętla foreach:");
        
                foreach ($arr as $el) {
                    echo $el . " "; 
                }

                hr();

                // ZADANIE 2
                
                $ex2 = "Min: " . min($arr) .", max: ". max($arr);
                ex('1', $ex2);


                // ZADANIE 3
                $sum = 0;

                foreach ($arr as $el) {
                    $sum += $el;
                }

                $ex3 = "Średnia: " . $sum / count($arr);

                ex("2", $ex3);

                // ZADANIE 4

                $count = 0;

                foreach ($arr as $el) {
                    if ($el == 3) {
                        $count++;
                    }
                }

                $ex4 = "Ilość trójek w tablicy: $count";
                ex("4", $ex4);

                // ZADANIE 5
                
                $p = 0;
                $np = 0;

                foreach ($arr as $el) {
                    if ($el % 2 == 0) {
                        $p++;
                    } else {
                        $np++;
                    }
                }

                $ex5 = "Parzystych: $p, nieparzystych: $np";

                ex("5", $ex5);

                // ZADANIE 6
                $sump = 0;
                $sumnp = 0;

                foreach ($arr as $el) {
                    if ($el % 2 == 0) {
                        $sump += $el;
                    } else {
                        $sumnp += $el;
                    }
                }

                $ex6 = "Suma parzystych: $sump, suma nieparzystych: $sumnp";
                ex("6", $ex6);
            ?>
        </div>
    </main>
</body>
</html>