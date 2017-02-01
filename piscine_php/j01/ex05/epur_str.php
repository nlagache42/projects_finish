<?php
function filter($var)
{
	return ($var !== NULL && $var !== FALSE && $var !== '');
}

if ($argc == 2)
{
	$test = str_replace("\t", " ", $str);
	$test = explode(" ", $argv[1]);
	$new = array_filter($test, 'filter');
	foreach ($new as $key => $value)
	{
		if ($end == NULL)
			$end = $value;
		else
			$end = "$end $value";
	}
	echo "$end\n";
}
?>