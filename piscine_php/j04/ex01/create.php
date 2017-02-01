<?php
if ($_POST["login"] == "" || $_POST["passwd"] == "")
	echo "ERROR\n";
else if ($_POST["submit"] == "OK")
{
	$password = hash("whirlpool", $_POST["passwd"]);
	if (file_exists("../private") == FALSE)
		mkdir("../private", 0777, true);
	if (file_exists("../private/passwd") == FALSE)
	{
		$tab = array(array("login"=>$_POST["login"], "passwd"=>$password));
		$serial_key = serialize($tab);
		file_put_contents("../private/passwd", $serial_key);
		echo "OK\n";
	}
	else
	{
		$tab = file_get_contents("../private/passwd");
		$serial_key = unserialize($tab);
		foreach ($serial_key as $value)
		{
			if ($value["login"] == $_POST["login"])
				$register = TRUE;
		}
		if ($register != TRUE)
		{
			$serial_key[] = array("login"=>$_POST["login"], "passwd"=>$password);
			$new_serial_key = serialize($serial_key);
			file_put_contents("../private/passwd", $new_serial_key);
			echo "OK\n";
		}
		else
			echo "ERROR\n";
	}
}
else
	echo "ERROR\n";
?>