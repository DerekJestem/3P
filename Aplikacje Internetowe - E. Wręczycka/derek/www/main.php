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
    <link rel="stylesheet" href="../style/main.css">
</head>
<body>
    <header>
        <div class="header-container">
            <h1>TEXT</h1>
            <?php
                if (isset($_SESSION['logged'])){
                    if (!$_SESSION['logged']) {
                        echo "
                            <nav>
                                <a href='./login.php'>Zaloguj się</a>
                                <a href='./register.php'>Zarejestruj się</a>
                            </nav>
                        ";
                    } else {
                        echo "
                            <nav>
                                <a href='./logout.php'>Wyloguj się</a>
                            </nav>
                        ";
                    }
                } else {
                    echo "
                        <nav>
                            <a href='./login.php'>Zaloguj się</a>
                            <a href='./register.php'>Zarejestruj się</a>
                        </nav>
                    ";
                }
            ?>
        </div>
    </header>
    <main>
        <p></p>
    </main>
    <footer></footer>
</body>
</html>