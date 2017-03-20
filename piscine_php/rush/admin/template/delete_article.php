<?php
session_start();
	if (isset($_SESSION['admin_log']))
	{
		if (isset($_GET['id']))
		{
			$mysqli = new mysqli("localhost", "root", "", "ecom");
			if (!($result = $mysqli->query("DELETE FROM articles WHERE id = '" . $_GET['id'] . "'")))
				echo "Erreur, impossible de se connecter a la base de donnée.";
			header("Location: ../list_object.php");
		}
	}
	else {
		echo "Error";
	}
?>
