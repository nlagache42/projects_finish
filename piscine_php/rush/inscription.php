<?php
session_start();
?>
<html>
<head>
	<link href="style/style.css" type="text/css" rel="stylesheet" />
</head>
<?php include("include/header.php");?>
<form class="connect_user" action="template/register.php" method="POST">
	<h2>Inscription</h2><br />
	<h3>Nom d'utilisateur :</h3><input type="text" name="login"/><br/><br/>
	<h3>Adresse Email :</h3><input type="text" name="mail" value=""/><br/><br/>
	<h3>Mot de passe :</h3><input type="password" name="passwd" value=""/><br/><br/>
	<h3>Confirmez le mot de passe :</h3><input type="password" name="confirm_passwd" value=""/><br/><br/>
	<input type="submit" name="submit" value="Créer son compte" /><br/><br/>
</form>
<?php include("include/footer.php");?>
</html>