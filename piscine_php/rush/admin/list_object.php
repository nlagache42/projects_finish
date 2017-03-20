<?php
include("include/header_admin.php");
include("../include/footer.php");
if ($_SESSION['admin_log'] !== NULL)
	{
		$mysqli = new mysqli("localhost", "root", "", "ecom");
		if (!($result = $mysqli->query("SELECT id, name, price FROM articles")))
			echo "Erreur, impossible de se connecter a la base de donnée.";
		echo '<h2 class="admin">Liste des produits</h2><br />';
		while ($row = $result->fetch_row())
		{
			echo '<h2>' . $row[1] . '</h2><a href="template/delete_article.php?id=' . $row[0] . '">SUPRIMER</a> -- <a href="modif_article.php?id=' . $row[0] . '">MODIFIER</a><br>';
		}
		if (!($result = $mysqli->query("SELECT id, login, mail FROM users")))
			echo "Erreur, impossible de se connecter a la base de donnée.";
	}
	else
	{
		echo "<h1>Vous n'avez pas acces a cet page </h1>";
	}
?>
