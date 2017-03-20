<?php
session_start();
$_SESSION['panier'][$_GET['objects']] = NULL;
$_SESSION['panier'] = array_filter($_SESSION['panier']);
header("Location: ../panier.php");
?>