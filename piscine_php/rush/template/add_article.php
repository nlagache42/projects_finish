<?php
session_start();
if (isset($_SESSION['panier']))
	$tab = $_SESSION['panier'];
else
	$tab = array();
if (isset($_GET['id']))
{
	foreach ($_SESSION as $value)
	{
		if ($value == $_GET['id'])
			header("Location: ../index.php");
	}
	array_push($tab, $_GET['id']);
	$_SESSION['panier'] = $tab;
}
header("Location: ../index.php");
?>
