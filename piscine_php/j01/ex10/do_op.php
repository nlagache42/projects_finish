<?php
if ($argc == 4)
{
	$nb1 = trim($argv[1]);
	$nb2 = trim($argv[3]);
	$op = trim($argv[2]);

	if ($op == "+")
		$res = $nb1 + $nb2;
	else if ($op == "-")
		$res = $nb1 - $nb2;
	else if ($op == "*")
		$res = $nb1 * $nb2;
	else if ($op == "/")
		$res = $nb1 / $nb2;
	else if ($op == "%")
		$res = $nb1 % $nb2;
	echo "$res\n";
}
else
	echo "Incorrect Parameters\n";
?>