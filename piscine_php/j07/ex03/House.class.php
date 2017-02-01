<?php abstract class House
{
	abstract public function getHouseName();
	abstract public function getHouseSeat();
	abstract public function getHouseMotto();
	public function introduce()
	{
		print("House ");
		print($this->getHouseName() . " of ");
		print($this->getHouseSeat() . ' : "');
		print($this->getHouseMotto(). '"' . PHP_EOL);
	}
}?>