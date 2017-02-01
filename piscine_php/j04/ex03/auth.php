<?php
function auth($login, $passwd)
{
	$pwd = hash("whirlpool", $passwd);
	$account = file_get_contents("../private/passwd");
	$serial_key = unserialize($account);
	foreach ($serial_key as $value)
	{
		if ($value["login"] == $login && $value["passwd"] == $pwd)
			$auth = TRUE;
	}
	if ($auth == TRUE)
		return (TRUE);
	else
		return (FALSE);
}
?>