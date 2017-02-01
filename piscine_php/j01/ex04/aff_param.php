<?php
foreach ($argv as $val)
{
	if ($val != $argv[0])
	{
		echo $val;
		echo "\n";
	}
}
?>