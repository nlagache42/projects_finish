<?php
session_start();
require_once("include/header.php");
$mysqli = new mysqli("localhost", "root", "", "ecom");
if (!($result = $mysqli->query("SELECT * FROM articles")))
	echo "Erreur, impossible de se connecter a la base de donnée.";
?>
<?php
echo '<div id="corp">';
while ($row = $result->fetch_row())
{
echo '<div class="article" style="height:200px">';
	if ($row[0] > 4)
		echo '<img class="img" src="http://www.stickers-center.com/594-home_default/sticker-domaine-du-geek.jpg">';
	else
		echo '<img class="img" src="include/dd' . $row[0] . '.jpeg">';
	echo '<div class="name">';
	echo $row[1];
	echo '</div><div class="desc">';
	echo $row[3];
	echo '</div><br><div class="price">Prix : ';
	echo $row[2];
	echo '&#8364;</div><a href="template/add_article.php?id=' . $row[0] . '"><br>Ajouter au panier</a></div>';
}
echo '</div>';
require_once("include/footer.php");
?>