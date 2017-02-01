<?php
function filter($var)
{
	return ($var !== NULL && $var !== FALSE && $var !== '');
}

function ft_split($str)
{
	$test = explode(" ", $str);
	$new = array_filter($test, 'filter');
	natcasesort($new);
	return ($new);
}


$num = array();
$alpha = array();
$other = array();
foreach ($argv as $val)
{
	if ($val != $argv[0])
	{
		$tab = ft_split($val);
		foreach ($tab as $val)
		{
			if (is_numeric($val[0]))
				array_push($num, $val);
			elseif ((ord($val[0]) >= 65 && ord($val[0]) <= 91) || (ord($val[0]) >= 97 && ord($val[0]) <= 123))
				array_push($alpha, $val);
			else
				array_push($other, $val);
		}
	}
}
natcasesort($alpha);
sort($num, SORT_STRING);
natcasesort($other);
$end = array_merge($alpha, $num, $other);
foreach ($end as $view)
	echo "$view\n";
?>