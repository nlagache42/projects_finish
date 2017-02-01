#!/usr/bin/php
<?php
function replace_all_link($tab)
{
	return preg_replace("/$tab[2]/", strtoupper($tab[2]), $tab[0]);
}

function replace_title($tab)
{
	return preg_replace("/$tab[2]/", strtoupper($tab[2]), $tab[0]);
}

function replace_other($tab)
{
	$tab[0] = preg_replace("/$tab[3]/", strtoupper($tab[3]), $tab[0]);
	$tab[0] = preg_replace("/$tab[7]/", strtoupper($tab[7]), $tab[0]);
	$tab[0] = preg_replace("/$tab[4]/", strtolower($tab[4]), $tab[0]);
	return preg_replace("/$tab[5]/", strtoupper($tab[5]), $tab[0]);
}

if (count($argv) < 2)
	exit();
else
{
	$entry = file_get_contents($argv[1]);
	$tab = preg_replace_callback("/(<a href=.+>(.+)<\/a>)/U", "replace_all_link", $entry);
	$tab = preg_replace_callback("/(<a href=.+>((.*)(<.*>)(.*))*<\/a>)/U", "replace_other", $tab);
	$tab = preg_replace_callback("/(.*)title=\"(.+)\"/", "replace_title", $tab);
	echo "$tab";
}
?>