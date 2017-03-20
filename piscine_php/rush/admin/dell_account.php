<?php
include("include/header_admin.php");
include("../include/footer.php");
if (isset($_SESSION['admin_log']))
	{
		$mysqli = new mysqli("localhost", "root", "", "ecom");
		if (!($result = $mysqli->query("SELECT id, login, mail, admin FROM users")))
			echo "Erreur, impossible de se connecter a la base de donnée.";
?>
		<h2 class="admin">Utilisateurs :</h2><br>
<?php
		while ($row = $result->fetch_row())
		{
			echo '<h2>LOGIN: ' . $row[1] . ' - MAIL: ' . $row[2] . ' - DROITS: ' . $row[3] . ' --> <a href="template/delete_user.php?id=' . $row[0] . '">SUPPRIMER</a></h2>';
		}
	}
else
	{
		echo "<h1>Vous n'avez pas acces a cet page </h1>";
	}
?>