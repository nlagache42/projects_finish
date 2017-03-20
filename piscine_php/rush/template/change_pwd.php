<?php
session_start();
if ($_POST["oldpw"] == "" || $_POST["newpw"] == "" || ($_POST["oldpw"] == $_POST["newpw"]) || ($_POST["newpw"]) !== ($_POST["newpw2"]))
	echo "Mauvais mot de passe, rententez votre chance\n";
else if ($_POST["submit"] == "OK")
{
	$mysqli = new mysqli("localhost", "root", "", "ecom");
	$result = $mysqli->query("SELECT login, password, mail FROM users");
	$old_password = hash("whirlpool", $_POST["oldpw"]);
	$login = $_SESSION["loggued_on_user"];
	while ($row = $result->fetch_row())
	{
		if ($login == $row[0] && $old_password == $row[1])
		{
			$new_password = hash("whirlpool", $_POST["newpw"]);
			$sql = "UPDATE users SET password = '$new_password' WHERE login='$login'";
			$mysqli->query($sql);
			header("Location: ../index.php");
		}
	}
}
else
	echo "Mauvais mot de passe\n";
?>