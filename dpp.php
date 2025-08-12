<?php
$temp = $_GET['temp'];
$from = $_GET['from'];
$to = $_GET['to'];
$output = shell_exec("convert.exe $temp $from $to");
echo $output;
?>
