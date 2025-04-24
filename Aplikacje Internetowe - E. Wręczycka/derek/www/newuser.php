<?php
    session_start();

    $username = @$_POST['username'];
    $password = @$_POST['password'];
    $globalName = @$_POST['globalname'];
    $emailAdress = @$_POST['email'];

    if (
        isset($username) &&
        isset($password) &&
        isset($globalName) &&
        isset($emailAdress)
    ) {
        $conn = mysqli_connect("localhost", "root", "", "firma");

        $query = mysqli_query($conn, "SELECT EXISTS(SELECT 1 FROM users WHERE username = '$username');");
        $registered = mysqli_fetch_all($query)[0][0];

        
        if ($registered == 0) {
            $hashed = hash("sha256", $password);
            $insert = mysqli_query($conn, "INSERT INTO users VALUES (NULL, '$username', '$hashed', '$globalName', '$emailAdress');");
            $_SESSION["logged"] = true;
            header("Location: http://localhost/derek/www/main.php");
        } else {
            $_SESSION["regErrMsg"] = "Podana nazwa użytkownika jest już zajęta!";
            header("Location: http://localhost/derek/www/register.php");
            exit();
        }
    } else {
        $_SESSION["regErrMsg"] = "Wystąpił problem. Spróbuj ponownie poźniej.";
        header("Location: http://localhost/derek/www/register.php");
    }
?>