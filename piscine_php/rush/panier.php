<?php
session_start();
 include("include/header.php");?>
<?php
	if ($_SESSION['panier'])
	{
		$mysqli = new mysqli("localhost", "root", "", "ecom");
		if (!($result = $mysqli->query("SELECT id, name, price FROM articles")))
			echo "Erreur, impossible de se connecter a la base de donnée.";
		echo '<div id="corp" style="margin-top:30px">';
		echo '<h2>Nombre d\'articles dans le panier : ' . count($_SESSION['panier']) . '</h2><br>';
		while ($row = $result->fetch_row())
		{
			foreach ($_SESSION['panier'] as $key => $value)
			{
				if ($row[0] == $value)
				{
					echo '<h3>Nom: ' . $row[1] . ' Prix: ' . $row[2] . '&#8364</h3>';
					echo '<h3><a href="template/remove.php?objects='.$key.'">Supprimer</a></h3><br>';
					$total += $row[2];
				}
			}
		}
		echo '<h2 class="total">TOTAL: ' . $total . '&#8364</h2>';
		if ($_SESSION['loggued_on_user'])
			echo '<a href=\'template/buy.php\'>ACHETER</a>';
		else
			echo '<h2 style="color:#581845;"class="panier">Vous devez être connecté pour acheter.</h2>';
	}
	else
		echo '<br><br><h2>Le panier est vide</h2>';
include("include/footer.php");?>
</html>
