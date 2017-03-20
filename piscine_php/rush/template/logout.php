<?php
session_start();
$_SESSION["loggued_on_user"] = NULL;
$_SESSION['admin_log'] = NULL;
$_SESSION['panier'] = NULL;
header("Location: ../index.php");
?>