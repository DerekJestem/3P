<?php

try {
    $pdo = new PDO("mysql:host=localhost;dbname=kalendarz", "root", "");
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    $currentDate = new DateTime();

    $dateForQuery = $currentDate->format('m-d');

    $stmt = $pdo->prepare("SELECT imiona FROM imieniny WHERE DATE_FORMAT(data, '%m-%d') = :date");
    $stmt->execute(['date' => $dateForQuery]);
    $result = $stmt->fetch(PDO::FETCH_ASSOC);

    $names = $result ? $result['imiona'] : 'Brak danych';

    $daysOfWeek = [
        1 => 'Poniedziałek',
        2 => 'Wtorek',
        3 => 'Środa',
        4 => 'Czwartek',
        5 => 'Piątek',
        6 => 'Sobota',
        7 => 'Niedziela'
    ];

    $dayOfWeek = $daysOfWeek[(int)$currentDate->format('N')];
    $dateFormatted = $currentDate->format('d-m-Y');

    echo "Dzisiaj jest $dayOfWeek, $dateFormatted, imieniny: $names";

} catch (PDOException $e) {
    echo "Błąd połączenia z bazą danych: " . $e->getMessage();
}
?>
