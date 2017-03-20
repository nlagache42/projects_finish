<?php
function auth($login, $passwd)
{
	$pwd = hash("whirlpool", $passwd);
	$mysqli = new mysqli("localhost", "root", "", "ecom");
	if (!($result = $mysqli->query("SELECT login, password, admin FROM users")))
		echo "Erreur, impossible de se connecter a la base de donnée.";
	while ($row = $result->fetch_row())
	{
		if ($login == $row[0] && $pwd == $row[1])
		{
			if ($row[2] == TRUE)
				$_SESSION['admin_log'] = $login;
			return (TRUE);
		}
	}
	return (FALSE);
}

session_start();
if ($_POST["submit"] == "Se connecter")
{
	if (auth($_POST["login"], $_POST["passwd"]) == TRUE)
	{
		$_SESSION["loggued_on_user"] = $_POST["login"];
		header("Location: ../index.php");
	}
	else
	{
		$_SESSION["loggued_on_user"] = "";
		header("Location: ../Connection_fail.php");
	}
}
?>