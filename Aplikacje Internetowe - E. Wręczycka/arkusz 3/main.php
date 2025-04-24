<?php
    try {
        $pdo = new PDO("mysql:host=localhost;dbname=kalendarz", "root", "");

        $currentDate = new DateTime();
        $formated = $currentDate->format('m-d');

        $query = "SELECT imiona FROM imieniny WHERE data = :date;";
        $stmt = $pdo->prepare($query);
        $stmt->execute(['date' => $formated]);
        $result = $stmt->fetch(PDO::FETCH_ASSOC);

        $days = [
            1 => 'Poniedziałek',
            2 => 'Wtorek',
            3 => 'Środa',
            4 => 'Czwartek',
            5 => 'Piątek',
            6 => 'Sobota',
            7 => 'Niedziela'
        ];

        echo "Dzisiaj jest " . $days[(int)$currentDate->format('N')] . ", " . $currentDate . ", imieniny: " . $result;
    }
    catch (PDOException $e) {
        $pdo->rollBack();
        echo 'Błąd połączenia: ' . $e->getMessage();
        exit;
    }