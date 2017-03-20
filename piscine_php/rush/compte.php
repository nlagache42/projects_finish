<?php
session_start();
	include("include/footer.php");
	include("include/header.php");
?>
<!DOCTYPE html>
<html>
	<head>
		<link href="style/style.css" type="text/css" rel="stylesheet" />
		<h2 class="compte">Changer mon mots de passe</h2>
		<form class="connect_user" action="template/change_pwd.php" method="POST">
			<h3>Ancien mot de passe :</h3><input type="password" name="oldpw" value=""/><br/><br/>
			<h3>Nouveau mot de passe :</h3><input type="password" name="newpw" value=""/><br/><br/>
			<h3>Confirmez le mot de passe :</h3><input type="password" name="newpw2" value=""/><br/><br/>
		<input type="submit" name="submit" value="OK" /><br/><br/>
	</form>
	</head>
</html>