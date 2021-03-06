#include <iostream>
#include <list>
using namespace std;


//Übungsblatt Bsp 1.9

int pow_function(int number,int power)
{
	long long unsigned int sum = 1;
	for(int i = power; i!=0;i--)
	{
		sum=(sum*number) % 99991;

	}
	return sum;
}

int hash_function(char character, int iteration, int length)
{ long long unsigned int y = ((int)character * pow_function(31,(length-iteration-1)))%99991;
	
	return y;

}

int main()
{

	char string[] ="FHTechnikumWien";
	int length = 0;
	for(int i = 0; ;i++)
	{
		if(string[i]=='\0')
		break;
		length++;
	}
	cout << length << endl;
	int index = 0;
	char symbol;
	long long unsigned int x = 0;
	long long unsigned int y = 0;
	while(42)	{
		symbol = string[index];
		if(symbol == '\0')
		break;
		y = hash_function(symbol,index,length);
		x +=y;
		
		cout << symbol <<" -> " << y << endl;
		index++;
	}
	cout << string << "->" << x << endl;
	cout << string << "->" << x%99991 << endl;
}