<?php
session_start();
?>
<html>
<head>
	<link href="style/style.css" type="text/css" rel="stylesheet" />
</head>
<?php include("include/header.php");?>
<form class="connect_user" action="template/login.php" method="POST">
	<h3>Identifiant :</h3><input type="text" name="login"/><br/><br/>
	<h3>Mot de passe :</h3><input type="password" name="passwd" value=""/><br/><br/>
	<input type="submit" name="submit" value="Se connecter" /><br/><br/>
</form>
<?php
include("include/footer.php");?>
</html>