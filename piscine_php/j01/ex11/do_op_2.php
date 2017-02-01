<?php
if ($argc != 2)
	echo "Syntax Error\n";
else
{
	$is_valid = sscanf($argv[1], "%d %c %d %s");
	if ($is_valid[0] && $is_valid[1] && $is_valid[2] && !$is_valid[3])
	{
		if ($is_valid[1] == "+")
			echo $is_valid[0] + $is_valid[2];
		else if ($is_valid[1] == "-")
			echo $is_valid[0] - $is_valid[2];
		else if ($is_valid[1] == "*")
			echo $is_valid[0] * $is_valid[2];
		else if ($is_valid[1] == "/")
			echo $is_valid[0] / $is_valid[2];
		else if ($is_valid[1] == "%")
			echo $is_valid[0] % $is_valid[2];
		else
			echo "Syntax Error\n";
	}
	else
		echo "Syntax Error\n";
}
?>