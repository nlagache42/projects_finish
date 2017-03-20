<?php
$mysqli = new mysqli("localhost", "root", "");
if ($mysqli->connect_errno)
	echo "Echec lors de la connexion à MySQL : (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
else
{
	if (!$mysqli->query("DROP DATABASE IF EXISTS ecom") || !$mysqli->query("CREATE DATABASE ecom"))
		echo "Echec de la création de la base de donnée.<br>";
	mysqli_select_db($mysqli, "ecom");
	if (!$mysqli->query("DROP TABLE IF EXISTS users") || !$mysqli->query("DROP TABLE IF EXISTS articles") || !$mysqli->query("DROP TABLE IF EXISTS panier") || !$mysqli->query("DROP TABLE IF EXISTS Save") ||
		!$mysqli->query("CREATE TABLE `articles` (`id` int(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL,`name` varchar(255) NOT NULL,`price` int(255) NOT NULL,`description` text NOT NULL,`stock` int(6), `categorie` varchar(255))") ||
		!$mysqli->query("CREATE TABLE `users` (`id` int(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY NOT NULL, `login` varchar(255) NOT NULL, `password` varchar(255) NOT NULL, `mail` varchar(255) NOT NULL, `admin` tinyint(1) NOT NULL)") ||
		!$mysqli->query("CREATE TABLE `Save` (`user_login` varchar(255) NOT NULL, `article_id` int(11) NOT NULL, `AddedOnDate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP )") ||
		!$mysqli->query("CREATE TABLE `panier` (`id_user` int(11) NOT NULL, `id_article` int(11) NOT NULL)"))
		echo "Echec de la creation des tables.";

	if (!$mysqli->query("INSERT INTO `users` ( `login`, `password`, `mail`, `admin`) VALUES ('admin', '" . hash("whirlpool", 'admin') . "', 'admin@gmail.com', TRUE)"))
		echo "Echec de l'ajout du compte administrateur";
	if (!$mysqli->query("INSERT INTO `articles` (`id`, `name`, `price`, `description`, `stock`) VALUES
	(1, 'Hitachi Deskstar NAS 3 To SATA 6Gb/s', 185, 'Les disques durs Hitachi (HGST) Deskstar NAS offrent d\'excellentes performances et une haute fiabilité. Grâce à leur vitesse haut débit et leur excellente durabilité, ces disques durs seront un achat idéal pour équiper une solution de stockage NAS (professionnelle ou grand public).', 14),
	(2, 'ASRock 775i65G R3.0', 64, 'Au format Micro ATX et équipée du jeu de composants Intel 865G, la carte mère ASRock 775i65G R3.0 représente une solution idéale pour l\'assemblage d\'une petite configuration performante, peu encombrante et optimisée pour la pratique de l\'informatique au quotidien.', 6),
	(3, 'AMD A10-7700K (3.5 GHz) Black Edition', 99, 'Le processeur AMD A10-7700K (3.5 GHz) Black Edition est si révolutionnaire qu\'il bouleverse la définition même de processeur. Avec sa multitude de coeurs intégrant les coeurs graphiques AMD Radeon R7 et des fonctionnalités exclusives comme la technologie AMD TrueAudio, il est parfait pour les Jeux', 8),
	(4, 'Ballistix Elite 16 Go (2 x 8 Go) DDR3 1866 MHz CL9', 176, 'Si vous découvrez la mémoire de performance, la gamme Ballistix Tactical de Crucial est un bon produit pour les utilisateurs enthousiastes. Cette gamme a été créée spécialement pour les joueurs. Elle fournit des performances accrues en termes de vitesse et de synchronisation.', 19)"))
		echo "Echec de la creation des articles.<br>";
}
?>
