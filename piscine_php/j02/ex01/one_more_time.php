#!/usr/bin/php
<?php
function checker($str)
{
	if ((preg_match("/(^[Ll]undi|^[Mm]ardi|^[Mm]ercredi|^[Jj]eudi|^[Vv]endredi|^[Ss]amedi|^[Dd]imanche){1} ([0-9]{1,2}) ([Jj]anvier|[Ff][eé]vrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Jj]uillet|[Aa]o[uû]t|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd][eé]cembre){1} ([0-9]){4} {1}([0-9]{2}:[0-9]{2}:[0-9]{2}){1}$/", $str)) != 0)
		return (TRUE);
	return (FALSE);
}

function month_val($month)
{
	if (preg_match("/([Jj]anvier)/", $month))
		return (1);
	else if (preg_match("/([Ff][eé]vrier)/", $month))
		return (2);
	else if (preg_match("/(Mm]ars)/", $month))
		return (3);
	else if (preg_match("/([Aa]vril)/", $month))
		return (4);
	else if (preg_match("/([Mm]ai)/", $month))
		return (5);
	else if (preg_match("/([Jj]uin)/", $month))
		return (6);
	else if (preg_match("/([Jj]uillet)/", $month))
		return (7);
	else if (preg_match("/([AÁa]o[uû]t)/", $month))
		return (8);
	else if (preg_match("/([Ss]eptembre)/", $month))
		return (9);
	else if (preg_match("/([Oo]ctobre)/", $month))
		return (10);
	else if (preg_match("/([Nn]ovembre)/", $month))
		return (11);
	else if (preg_match("/([Dd][eé]cembre)/", $month))
		return (12);
	else
		send_error();
}

function send_error()
{
	echo "Wrong Format\n";
	exit();
}

if ($argc == 2)
{
	if (checker($argv[1]) == FALSE)
		echo "Wrong Format\n";
	else
	{
		preg_match("(^[Ll]undi|^[Mm]ardi|^[Mm]ercredi|^[Jj]eudi|^[Vv]endredi|^[Ss]amedi|^[Dd]imanche)", $argv[1], $jour);
		preg_match("/([0-9]{1,2})/", $argv[1], $number);
		preg_match("/([Jj]anvier|[Ff][eé]vrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Jj]uillet|[AÁa]o[uû]t|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd][eé]cembre)/", $argv[1], $month);
		preg_match("/[0-9]{4}/", $argv[1], $year);
		preg_match("/[0-9]{2}:/", $argv[1], $hour);
		preg_match("/:[0-9]{2}:/", $argv[1], $min);
		preg_match("/:[0-9]{2}$/", $argv[1], $sec);
		$hour[0] = substr($hour[0], 0, 2);
		$min[0] = substr($min[0], 1, 2);
		$sec[0] = substr($sec[0], 1, 2);
		$month_val = month_val($month[0]);
		if ($jour == NULL || $number == NULL || $month == NULL || $year == NULL || $hour == NULL || $min == NULL || $sec == NULL || intval($number[0]) > 31 || intval($number[0]) < 1 || intval($hour[0]) > 23 || intval($hour[0]) < 0 || intval($min[0]) > 60 || intval($min[0]) < 0 || intval($sec[0]) > 59 || intval($sec[0]) < 0 || intval($year[0]) < 1970)
			send_error();
		date_default_timezone_set('Europe/Paris');
		echo mktime($hour[0], $min[0], $sec[0], $month_val, $number[0], $year[0]);
		echo "\n";
	}
}
?>