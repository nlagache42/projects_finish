<?php
function ft_split_no($s1)
{
	$tab = explode(" ", $s1);
	return($tab);
}

	$eleme = trim($argv[1]);
	$tab = str_replace("  ", " ", $eleme);
	while (strstr($tab, "  "))
	{
		$tab = str_replace("  ", " ", $tab);
	}
	$my_tab = explode(" ", $tab);
	$first = array_shift($my_tab);
	foreach($my_tab as $el)
	{
		echo $el;
		echo " ";
	}
	echo $first;
	if ($argc > 1)
		echo "\n";
?>