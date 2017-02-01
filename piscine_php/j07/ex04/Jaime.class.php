<?php
class Jaime extends Lannister
{
	public function Ken($object)
	{
		if (get_parent_class($object) !== 'Lannister')
			return ("Let's do this.");
		else
		{
			if (get_class($object) === 'Cersei')
				return ("With pleasure, but only in a tower in Winterfell, then.");
			else
				return ("Not even if I'm drunk !");
		}
	}
}
?>