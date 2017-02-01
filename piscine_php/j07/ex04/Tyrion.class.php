<?php
Class Tyrion extends Lannister
{
	public function Ken($object)
	{
		if (get_parent_class($object) !== 'Lannister')
			return ("Let's do this.");
		return ("Not even if I'm drunk !");
	}
}
?>