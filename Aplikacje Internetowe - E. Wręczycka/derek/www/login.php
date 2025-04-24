<?php
    session_start();
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Strona główna</title>
    <link rel="stylesheet" href="../style/default.css">
    <link rel="stylesheet" href="../style/login.css">
</head>
<body>
    <main>
        <div class="login-container">
            <?php
                if (isset($_SESSION["regErrMsg"])) {
                    echo "<p>" . $_SESSION["regErrMsg"] . "</p>";
                    $_SESSION["regErrMsg"] = null;
                }
            ?>
            <form action="./auth.php">
                <label for="username">Nazwa użytkownika
                    <input type="text" name="username" id="username">
                </label>
                <label for="password">Hasło
                    <input type="password" name="password" id="password">
                </label>
                <input type="submit" value="Zaloguj się">
            </form>
            <p>Nie posiadasz konta? <a href="./register.php">Zarejestruj się</a></p>
        </div>
    </main>
</body>
</html>