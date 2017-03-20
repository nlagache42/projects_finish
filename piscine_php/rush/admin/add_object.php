<?php
session_start();
include("include/header_admin.php");
include("../include/footer.php");
?>
<!DOCTYPE html>
<html>
	<head>
		<link href="../style/style.css" type="text/css" rel="stylesheet" />
		<title>Administration</title>
	</head>
	<h2 class="admin">Ajouter un article</h2><br>
	<form action="new_article.php" method="post">
		<h3>Categorie:</h3><input type="text" name="categorie" value=""><br>
		<h3>Stock:</h3><input type="text" name="stock" value=""><br>	
		<h3>Nom:</h3><input type="text" name="name" value=""><br>
		<h3>Prix:</h3><input type="text" name="price" value=""><br>
		<h3>Description:</h3><textarea name="desc" rows="8" cols="80"></textarea><br>
		<input type="submit" name="submit" value="Ajouter">
	</form>
</html>
