<?php
session_start();
if ($_SESSION["loggued_on_user"] === "" || $_SESSION["loggued_on_user"] == FALSE)
	echo "ERROR\n";
else
	echo $_SESSION["loggued_on_user"]."\n";
?>