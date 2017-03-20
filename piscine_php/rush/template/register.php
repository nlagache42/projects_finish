<?php
if ($_POST["login"] == "" || $_POST["passwd"] == "" || $_POST["mail"] == "" || ($_POST["passwd"] != $_POST["confirm_passwd"]))
	header("Location: ../inscription_fail.php");
else if ($_POST["submit"] == "Créer son compte")
{
	if (!filter_var($_POST["mail"], FILTER_VALIDATE_EMAIL))
	{
		header ("Location: ../inscription.php");
		exit();
	}
	$password = hash("whirlpool", $_POST["passwd"]);
	$mysqli = new mysqli("localhost", "root", "", "ecom");
	$result = $mysqli->query("SELECT login, password, mail FROM users");
	while ($row = $result->fetch_row())
	{
		if ($row[0] == $_POST["login"])
			$register = TRUE;
	}
	if ($register != TRUE)
	{
		$sql = "INSERT INTO users (login, password, mail, admin) VALUES ('" . $_POST["login"] . "', '" . $password . "', '" . $_POST["mail"] . "', FALSE)";
		if (!$mysqli->query($sql))
			echo "Erreur mysql";
		header ("Location: ../Connection.php");
	}
	else
	{
		header("Location: ../inscription_fail.php");
	}
}
else
	header("Location: ../inscription_fail.php");
?>
