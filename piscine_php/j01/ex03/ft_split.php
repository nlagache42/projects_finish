<?php
function filter($var)
{
	return ($var !== NULL && $var !== FALSE && $var !== '');
}

function ft_split($str)
{
	if ($str != NULL)
	{
		$str = str_replace("\t", " ", $str);
		$test = explode(" ", $str);
		$new = array_filter($test, 'filter');
		sort($new);
	}
	return ($new);
}
?>