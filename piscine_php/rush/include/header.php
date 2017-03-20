<?php
session_start();
?>
<!DOCTYPE html>
<html>
	<head>
		<title>ToutPourLePc</title>
		<link href="style/style.css" type="text/css" rel="stylesheet" />
	</head>
	<header>
	<br/><h1 class="title">ToutPourLePc</h1><br/>
		<ul class="menu">
			<li><a href="index.php">Accueil</a></li>
			<?php
			echo '<li><a href="Panier.php">Panier (' . count($_SESSION['panier']) . ')</a></li>';

//<?php
if (!$_SESSION["loggued_on_user"])
{
?>
			<li><a href="Connection.php">Connexion</a></li>
			<li><a href="Inscription.php">Inscription</a></li>
<?php
}
else
{
?>
			<li><a href="Compte.php">Mon compte</a></li>
<?php
			if ($_SESSION['admin_log'])
			{
?>
				<li><a href="admin/index.php">Administration</a></li>
<?php
			}
?>
			<li><a href="template/logout.php">Deconnexion</a></li>
<?php
}
?>
		</ul>
	</header>
</html>