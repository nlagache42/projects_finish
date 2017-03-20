<?php
session_start();
	if (isset($_SESSION['admin_log']))
	{
		if (isset($_GET['id']))
		{
			$mysqli = new mysqli("localhost", "root", "", "ecom");
			if (!($result = $mysqli->query("DELETE FROM users WHERE id = '" . $_GET['id'] . "'")))
				echo "Erreur, impossible de se connecter a la base de donnée.";
			header("Location: ../dell_account.php");
		}
	}
	else {
		echo "Error";
	}
?>
