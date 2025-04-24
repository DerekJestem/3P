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
            <form action="./newuser.php" method="post">
                <label for="username">Nazwa użytkownika
                    <input type="text" name="username" id="username" required>
                </label>
                <label for="globalname">Wyświetlana nazwa
                    <input type="text" name="globalname" id="globalname" required>
                </label>
                <label for="email">Adres e-mail
                    <input type="email" name="email" id="email" required>
                </label>
                <label for="password">Hasło
                    <input type="password" name="password" id="password" required>
                </label>
                <input type="submit" value="Zaloguj się">
            </form>
            <p>Masz już konto? <a href="./login.php">Zaloguj się</a></p>
        </div>
    </main>
</body>
</html>