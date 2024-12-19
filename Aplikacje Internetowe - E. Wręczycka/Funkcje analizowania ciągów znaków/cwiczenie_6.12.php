<?php
$text = "To jest przykładowy tekst. To jest test.";
$word = "to";

$count = substr_count(strtolower($text), strtolower($word));

echo "\"$word\" występuje $count razy w tekscie.";
?>