<?php
function filter($var)
{
	return ($var !== NULL && $var !== FALSE && $var !== '');
}

function ft_split($str)
{
	$str = str_replace("\t", " ", $str);
	$test = explode(" ", $str);
	$new = array_filter($test, 'filter');
	sort($new);
	return ($new);
}

$end = array();
foreach ($argv as $val)
{
	if ($val != $argv[0])
	{
		$tab = ft_split($val);
		$end = array_merge($end, $tab);
	}
}
sort($end);
foreach ($end as $view)
{
	echo "$view\n";
}
?>