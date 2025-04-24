<?php
    session_start();

    $username = @$_POST['username'];
    $password = @$_POST['password'];

    if (
        isset($username) &&
        isset($password) 
    ) {
        $conn = mysqli_connect("localhost", "root", "", "firma");

        $query = mysqli_query($conn, "SELECT EXISTS(SELECT 1 FROM users WHERE username = '$username');");
        $registered = mysqli_fetch_all($query)[0][0];

        
        if ($registered == 1) {
            $hashed = hash("sha256", $password);

            $query2 = mysqli_query($conn, "SELECT password FROM users WHERE user = '$username'");
            $dbpassword = mysqli_fetch_all($query2)[0][0];

            if($hashed == $dbpassword) {
                $_SESSION['logged'] = 1;
                header("Location: http://location/derek/www/main.php");
                exit();
            } else {
                $_SESSION["logErrMsg"] = "Niepoprawna nazwa użytkownika lub hasło.";
                header("Location: http://location/derek/www/login.php");
                exit();
            }
        } else {
            $_SESSION["logErrMsg"] = "Użytkownik nie istnieje!";
            header("Location: http://localhost/derek/www/login.php");
            exit();
        }
    } else {
        $_SESSION["regErrMsg"] = "Wystąpił problem. Spróbuj ponownie poźniej.";
        header("Location: http://localhost/derek/www/register.php");
    }
?>