<?php
include("../include/footer.php");
?>
<head>
	<title>ToutPourLePc</title>
	<link href="../style/style.css" type="text/css" rel="stylesheet" />
</head>
<h1 class="admin">Administration</h1>
<form action="template/login_admin.php" method="POST">
	<h3>Login :</h3><input type="text" name="login"/><br/><br/>
	<h3>Mot de passe :</h3><input type="password" name="passwd" value=""/><br/><br/>
	<input type="submit" name="submit" value="Se connecter" /><br/><br/>
</form>