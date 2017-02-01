<?php
while(1)
{
	echo "Entrez un nombre: ";
	$line = trim(fgets(STDIN));
	$nbr = $line;
	$line = substr($line, -1);
	if (feof(STDIN) == true)
		exit();
	if (!is_numeric($nbr))
		echo "'$nbr' n'est pas un chiffre";
	else
	{
		echo "Le chiffre $nbr est ";
		if ($line % 2 === 0)
			echo "Pair";
		else
			echo "Impair";
	}
	echo "\n";
}
?>