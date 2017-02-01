<?php
if ($_POST["login"] == "" || $_POST["oldpw"] == "" || $_POST["newpw"] == "" || ($_POST["oldpw"] == $_POST["newpw"]) || (file_exists("../private/passwd") == FALSE))
	echo "ERROR\n";
else if ($_POST["submit"] == "OK")
{
	$new_password = hash("whirlpool", $_POST["newpw"]);
	$old_password = hash("whirlpool", $_POST["oldpw"]);
	$tab = file_get_contents("../private/passwd");
	$serial_key = unserialize($tab);
		foreach ($serial_key as $key => $value)
		{
			if ($value["login"] === $_POST["login"] && $value["passwd"] === $old_password)
			{
				$serial_key[$key]["passwd"] = $new_password;
				$register = TRUE;
			}
		}
		if ($register == TRUE)
		{
			$new_serial_key = serialize($serial_key);
			file_put_contents("../private/passwd", $new_serial_key);
			echo "OK\n";
		}
		else
			echo "ERROR\n";
}
else
	echo "ERROR\n";
?>