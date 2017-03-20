<?php
session_start();
$mysqli = new mysqli("localhost", "root", "", "ecom");
$result = $mysqli->query("SELECT user_login, article_id FROM Save");

foreach ($_SESSION['panier'] as $key => $value)
	{
		$sql = "INSERT INTO Save (user_login, article_id) VALUES ('" . $_SESSION["loggued_on_user"] . "', '" . $value . "')";
		if (!$mysqli->query($sql))
			echo "Erreur mysql";
	}
$_SESSION['panier'] = NULL;
header("Location: ../panier.php");
?>
