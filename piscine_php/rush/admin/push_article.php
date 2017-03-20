<?php
	session_start();
	if ($_SESSION['admin_log'] !== NULL)
	{
		if (isset($_GET['id']))
		{
			$mysqli = new mysqli("localhost", "root", "", "ecom");
			$stmt = $mysqli->prepare("UPDATE articles SET name = ?, description = ?, price = ? WHERE id = ?");
			$stmt->bind_param('ssii', $_POST['name'], $_POST['desc'], $_POST['price'], $_GET['id']);
			$stmt->execute();
			$stmt->close();
			header("Location: list_object.php");
		}
	}
	else {
		echo "Error";
	}
?>
