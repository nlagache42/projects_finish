<?php
class NightsWatch implements IFighter
{
	private $tab;

	public function recruit($test)
	{
		if ($test instanceof IFighter)
			$this->tab[] = $test;
	}
	public function fight()
	{
		foreach ($this->tab as $key => $value)
		{
			$value->fight();
		}
	}
}
?>