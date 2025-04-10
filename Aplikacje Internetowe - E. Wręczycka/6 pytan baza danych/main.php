<?php
    $conn = mysqli_connect("localhost", "root", "", "klienci");

    $query = mysqli_query($conn, "SELECT * FROM klienci");

    $prompt1 = "SELECT imie FROM klienci WHERE imie LIKE '_a%'";
    $prompt2 = "SELECT ulica FROM klienci WHERE ulica LIKE 'S%'";
    $prompt3 = "SELECT kod_pocztowy FROM klienci WHERE kod_pocztowy LIKE '8%'";
    $prompt4 = "SELECT email FROM klienci ORDER BY email";
    $prompt5 = "SELECT miejscowosc FROM klienci WHERE miejscowosc LIKE '%a' LIMIT 1";
    $prompt6 = "SELECT COUNT(miejscowosc) AS ilosc FROM klienci WHERE miejscowosc LIKE '%a'";


    $response = mysqli_fetch_all($query);

    $q1 = mysqli_query($conn, $prompt1);
    $q2 = mysqli_query($conn, $prompt2);
    $q3 = mysqli_query($conn, $prompt3);
    $q4 = mysqli_query($conn, $prompt4);
    $q5 = mysqli_query($conn, $prompt5);
    $q6 = mysqli_query($conn, $prompt6);

    $res1 = mysqli_fetch_all($q1);
    $res2 = mysqli_fetch_all($q2);
    $res3 = mysqli_fetch_all($q3);
    $res4 = mysqli_fetch_all($q4);
    $res5 = mysqli_fetch_all($q5);
    $res6 = mysqli_fetch_all($q6);
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TABELKA</title>
    <style>
        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }

        html {
            font-family: 'Calibri';
            background-color: whitesmoke;
        }

        main {
            width: 100%;
            min-height: 100vh;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: center;
            gap: 25px;
            padding: 50px 0;
            box-sizing: border-box;
        }

        main table {
            border-collapse: collapse;
            border: 2px solid black;
            margin-top: 25px;
        }
        th {
            background-color: whitesmoke;
        }

        td, th {
            border: 1px solid lightgray;
            padding: 5px 10px;
        }

        .prompt {
            color: rgba(0, 0, 0, 0.5);
        }

        .container {
            max-width: 1000px;
            width: 100%;
            background-color: white;
            display: flex;
            flex-direction: column;
            justify-content: center;
            align-items: flex-start;
            padding: 25px;
            border-radius: 10px;
            box-shadow: 10px 10px 15px rgba(0, 0, 0, 0.1);
        }
    </style>
</head>
<body>
    <main>
        <div class="container">
            <h1>TABELKA:</h1>
            <table>
                <tr>
                    <th>ID</th>
                    <th>Nazwisko</th>
                    <th>Imie</th>
                    <th>Kod pocztowy</th>
                    <th>Miejscowość</th>
                    <th>Ulica</th>
                    <th>Nr domu</th>
                    <th>PESEL</th>
                    <th>Telefon</th>
                    <th>E-mail</th>
                </tr>
                <?php
                    foreach ($response as $row) {
                        echo "<tr>";
    
                        foreach ($row as $value) {
                            echo "<td>" . $value . "</td>";
                        }
    
                        echo "</tr>";
                    }
                ?>    
            </table>
        </div>
        <div class="container">
            <h1>Zapytanie 1:</h1>
            <h3>Wyświetla imiona osób, których druga litera to 'a'</h3>
            <p class="prompt"><?= $prompt1; ?></p>
            <table>
                <tr>
                    <th>Imie</th>
                </tr>
                <?php
                    foreach ($res1 as $row) {
                        echo "<tr>";

                        foreach ($row as $value) {
                            echo "<td>" . $value . "</td>";
                        }

                        echo "</tr>";
                    }
                ?>
            </table>
        </div>
        <div class="container">
            <h1>Zapytanie 2:</h1>
            <h3>Wyświetla ulice na literę 'S'</h3>
            <p class="prompt"><?= $prompt2; ?></p>
            <table>
                <tr>
                    <th>Ulica</th>
                </tr>
                <?php
                    foreach ($res2 as $row) {
                        echo "<tr>";

                        foreach ($row as $value) {
                            

                            echo "<td>" . $value . "</td>";
                        }

                        echo "</tr>";
                    }
                ?>
            </table>
        </div>
        <div class="container">
            <h1>Zapytanie 3:</h1>
            <h3>Wyświetla kod pocztowy rozpoczynający się od '8'</h3>
            <p class="prompt"><?= $prompt3; ?></p>
            <table>
                <tr>
                    <th>Kod pocztowy</th>
                </tr>
                <?php
                    foreach ($res3 as $row) {
                        echo "<tr>";

                        foreach ($row as $value) {
                            echo "<td>" . $value . "</td>";
                        }

                        echo "</tr>";
                    }
                ?>
            </table>
        </div>
        <div class="container">
            <h1>Zapytanie 4:</h1>
            <h3>Posortuje od A do Z adresy e-mail</h3>
            <p class="prompt"><?= $prompt4; ?></p>
            <table>
                <tr>
                    <th>E-mail</th>
                </tr>
                <?php
                    foreach ($res4 as $row) {
                        if ($row[0] == "" || empty($row[0])) {
                            continue;
                        }

                        echo "<tr>";

                        foreach ($row as $value) {
                            echo "<td>" . $value . "</td>";
                        }

                        echo "</tr>";
                    }
                ?>
            </table>
        </div>
        <div class="container">
            <h1>Zapytanie 5:</h1>
            <h3>Wyświetla miejscowości kończące się literą 'a'</h3>
            <p class="prompt"><?= $prompt5; ?></p>
            <table>
                <tr>
                    <th>Miejscowość</th>
                </tr>
                <?php
                    foreach ($res5 as $row) {
                        echo "<tr>";

                        foreach ($row as $value) {
                            echo "<td>" . $value . "</td>";
                        }

                        echo "</tr>";
                    }
                ?>
            </table>
        </div>
        <div class="container">
            <h1>Zapytanie 6:</h1>
            <h3>Wyświetla ilość miejscowości kończących się lierą 'a'</h3>
            <p class="prompt"><?= $prompt6; ?></p>
            <table>
                <tr>
                    <th>Ilość miejscowości</th>
                </tr>
                <?php
                    foreach ($res6 as $row) {
                        echo "<tr>";

                        foreach ($row as $value) {
                            echo "<td>" . $value . "</td>";
                        }

                        echo "</tr>";
                    }
                ?>
            </table>
        </div>
    </main>
</body>
</html>