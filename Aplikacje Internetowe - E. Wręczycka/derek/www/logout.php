<?php
    session_start();
    session_destroy();
    session_abort();
    header("Location: http://localhost/derek/www/main.php")
?>