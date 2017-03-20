<?php
	session_start();
	if (isset($_SESSION['admin_log']))
	{
		if ($_POST['submit'] == 'Ajouter')
		{
			$mysqli = new mysqli("localhost", "root", "", "ecom");
			if (!($mysqli->query("INSERT INTO `articles`(`name`, `price`, `description`, `stock`, `categorie`) VALUES ('" . $_POST['name'] . "', '" . $_POST['price'] . "', '" . $_POST['desc'] . "', " . $_POST['stock'] . ", '" . $_POST['categorie'] . "')")))
				echo "Erreur, impossible de se connecter a la base de donnée.";
			header("Location: list_object.php");
		}
	}
	else {
		echo "Vous n'avez pas accès à cet page. <br>";
	}
?>
