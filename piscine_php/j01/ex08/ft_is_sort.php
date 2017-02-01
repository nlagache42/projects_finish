<?php
function ft_is_sort($tab)
{
	$tmp = $tab;
	sort($tab);
	foreach ($tab as $key=>$tmp2) 
	{
		if ($tmp2 != $tmp[$key])
			return (false);
	}
	return (true);
}
?>