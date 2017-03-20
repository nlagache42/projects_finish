<?php
	session_start();
	if (isset($_POST['login']) && isset($_POST['passwd']))
	{
		$pwd = hash("whirlpool", $_POST['passwd']);
		$mysqli = new mysqli("localhost", "root", "", "ecom");
		if (!($result = $mysqli->query("SELECT login, password, admin FROM users")))
			echo "Erreur, impossible de se connecter a la base de donnée.";
		while ($row = $result->fetch_row())
		{
			if ($_POST['login'] == $row[0] && $pwd == $row[1] && $row[2])
			{
				$_SESSION['admin_log'] = $_POST["login"];
				header("Location: ../list_object.php");
				exit();
			}
		}
		header("Location: ../index.php");
	}
?>
