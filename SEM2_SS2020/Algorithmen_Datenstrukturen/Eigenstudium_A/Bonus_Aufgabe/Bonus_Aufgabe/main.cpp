#include <iostream>

class Hashtable {
public:
	int _array[13];
	int added;
	int collisions;
	Hashtable()
		: _array{0}, added(0)
	{
	}
	
	int hash_function(int value)
	{
		int hash_index = 0;
		int collision_counter = 0;
		for (int i = 0; ; i++)
		{
			hash_index = value % 100;
			std::cout << value << " mod 100 = "<< hash_index << std::endl;
			std::cout << hash_index << " + " << i*i << " = ";
			hash_index += i * i;
			std::cout << hash_index << std::endl;
			std::cout << hash_index << " mod 13 = ";
			hash_index %=13;
			std::cout << hash_index << std::endl;
			if (_array[hash_index]==0)
				break;
			std::cout << "Collision detected! quadratic probing degree: " << i + 1 << std::endl;
			collision_counter++;
		}
		if (collision_counter > collisions)
			collisions = collision_counter;
		return hash_index;
	}
	bool add_value(int value)
	{
		if (added == 13)
		{
			return false;
		}
		int index = hash_function(value);
		std::cout << value << " is inserted at " << index << std::endl;
		_array[index] = value;
		added++;
		return true;
	}
	void fill_degree()
	{
		std::cout << "Fill Degree: " << ((float)added / 13 )* 100 << "%" << std::endl;
	}
};

int main()
{
	Hashtable my_hash;
	int values[6] = { 41025703, 41025717, 11025749, 41025773, 31024430, 41025782 };
	for(int i = 0; i<6;i++)
	{
		my_hash.add_value(values[i]);


	}
	std::cout << my_hash.added<< std::endl;
	my_hash.fill_degree();

}
//#############   SOLUTIONS   ################
//Fügen Sie folgende Datensätze in die Tabelle ein und geben Sie die benötigten Rechenschritte an: 
//041025703,041025717,011025749,041025773,031024430,041025782
		//Done, just execute and look for yourself

//Geben Sie den Füllgrad der Hashtabelle nach dem Einfügen der neuen Datensätze an. 
		//46.15%

//Welche Schritte sind bei der Suche des Datensatzes 041025782 notwendig?
		//Es sind 3 Schritte notwendig, um den Datensatz zu finden. Es ist eigentlich ganz leicht: hash_index berechnen.
		//Sollte es nicht an dieser Stelle sein, so lange mit quadratic probing loopen, bis man die max. Anzahl an Collisions erreicht wurden.
		//Sollte er noch imemr nicht vorhanden sein, abbruch, da der Datensatz nicht in der Hashtabelle ist. 

//Worauf muss beim Löschen eines Datensatzes in einer Hashtabelle mit Sondierung als Kollisionsbehandlung geachtet werden?
//Löschen Sie z.B. den Datensatz  031024430. 
		//Dass man den richtigen Datensatz löscht. Siehe oben, um den ihn zu finden. 