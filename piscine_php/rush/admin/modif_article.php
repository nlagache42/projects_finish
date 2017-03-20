<?php
session_start();
include("include/header_admin.php");
include("../include/footer.php");
 ?>
 <!DOCTYPE html>
 <html>
	<body>
	<?php
		$mysqli = new mysqli("localhost", "root", "", "ecom");
		if (!($result = $mysqli->query("SELECT id, name, price, description, categorie FROM articles WHERE id = '" . $_GET['id'] . "'")))
			echo "Erreur, impossible de se connecter a la base de donnée.";
		echo '<h2 class="admin" >Modifier article</h2><br>';
		while ($row = $result->fetch_row())
		{
			echo '<form action="push_article.php?id=' . $_GET['id'] . '" method="post">
					<h3>NOM:</h3><input type="text" name="name" value="' . $row[1] . '"><br><br>
					<h3>PRIX:</h3><input type="text" name="price" value="' . $row[2] . '"><br><br>
					<h3>DESCRIPTION:</h3><textarea name="desc" rows="8" cols="80">' . $row[3] . '</textarea><br><br>
					<h3>CATEGORIE:</h3><input type="text" name="categorie" value="' . $row[4] . '"><br><br>
					<input type="submit" name="submit" value="Modifier">
			</form>';
		}
	 ?>
 	</body>
 </html>
