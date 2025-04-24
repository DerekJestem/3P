<?php
// skrypt2.php - Script 2: Display name days for date from form

if ($_SERVER['REQUEST_METHOD'] === 'POST' && !empty($_POST['data'])) {
    $inputDate = $_POST['data'];

    try {
        $pdo = new PDO("mysql:host=localhost;dbname=kalendarz", "root", "");
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        // Convert input date to DateTime object
        $dateObj = DateTime::createFromFormat('Y-m-d', $inputDate);
        if (!$dateObj) {
            throw new Exception("Niepoprawny format daty. Użyj yyyy-mm-dd.");
        }

        // Format date for query mm-dd
        $dateForQuery = $dateObj->format('m-d');

        // Prepare and execute query 2 modified to check input date mm-dd
        $stmt = $pdo->prepare("SELECT imiona FROM imieniny WHERE DATE_FORMAT(data, '%m-%d') = :date");
        $stmt->execute(['date' => $dateForQuery]);
        $result = $stmt->fetch(PDO::FETCH_ASSOC);

        $names = $result ? $result['imiona'] : 'Brak danych';

        echo "Dnia $inputDate są imieniny: $names";

        // Close connection
        $pdo = null;

    } catch (PDOException $e) {
        echo "Błąd połączenia z bazą danych: " . $e->getMessage();
    } catch (Exception $e) {
        echo "Błąd: " . $e->getMessage();
    }
} else {
    // Display simple form to input date
    echo '<form method="POST" action="">
            <label for="data">Podaj datę (yyyy-mm-dd):</label>
            <input type="date" id="data" name="data" required>
            <input type="submit" value="Sprawdź imieniny">
          </form>';
}
?>
