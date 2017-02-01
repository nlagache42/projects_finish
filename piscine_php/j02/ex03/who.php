#!/usr/bin/php
<?php
if ($argc < 2)
{
	$user = get_current_user();
	$var_run_utmpx = file_get_contents("/var/run/utmpx");
	$sub = substr($var_run_utmpx, 1256);
	$end_value = array();
	$model = 'a256user/a4id/a32line/ipid/itype/I2time/a256host/i16pad';
	date_default_timezone_set('Europe/paris');
	while ($sub != NULL)
	{
		$v_sync = unpack($model, $sub);
		if (strcmp(trim($v_sync[user]), $user) == 0 && $v_sync[type] == 7)
		{
			$date = date("M j H:i ", $v_sync["time1"]);
			$result = trim($v_sync[line]);
			$result = $result . "  ";
			$second_user = trim($v_sync[user]);
			$second_user = $second_user . " ";
			$tab = array($second_user.$result.$date);
			$end_value = array_merge($end_value, $tab);
		}
		$sub = substr($sub, 628);
	}
	sort($end_value);
	foreach ($end_value as $elem)
	{
		echo $elem;
		echo "\n";
	}
}
?>