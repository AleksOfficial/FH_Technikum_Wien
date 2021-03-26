#include <iostream>
#include "hashtable.h"

//Perhaps these Functions can be moved into the Hashtable Class

void welcome_message()
{
	std::cout << "Welcome to your personal Stock program!" << std::endl;
}
void menu_options()
{
	std::cout << "These are your options: " << std::endl;
	std::cout << "   - ADD: Declares a Stock to your program." << std::endl;
	std::cout << "   - DEL: Deletes a Stock from your program, including the associated data." << std::endl;
	std::cout << "   - IMPORT: Imports a CSV-File and adds/overwrites the data to/of a stock. " << std::endl;
	std::cout << "   - SEARCH: Searches your program for the specified stock and prints latest data of it. " << std::endl;
	std::cout << "   - PLOT: Plots a your program for the specified stock and prints latest data of it. " << std::endl;
	std::cout << "   - SAVE <filename>: Saves your stock selection and data to a file with the specified name. " << std::endl;
	std::cout << "   - LOAD <filename>: Load your stock selection and data from a specified file. " << std::endl;
	std::cout << "   - QUIT: Exit the program. " << std::endl;
}


void input_handler(Hashtable &current_table,bool &running)
{
	std::cout << "Enter a command: " << std::endl;
	std::string command;
	std::cin >> command;
	current_table.to_upper(command);
	if (command == "ADD")
	{
		current_table.add();
	}
	else if (command == "DEL")
	{
		current_table.del();
	}
	else if (command == "IMPORT")
	{
		current_table.import_data();
	}
	else if (command == "SEARCH")
	{
		current_table.search();
	}
	else if (command == "PLOT")
	{
		current_table.plot();
	}
	else if (command == "SAVE")
	{
		current_table.save();
	}
	else if (command == "LOAD")
	{
		current_table.load();
	}
	else if (command == "QUIT")
	{
		current_table.quit();
		running = false;
	}
	else if (command == "PRINTTABLE")
	{
		current_table.print_table();

	}
	else if (command == "PRINTNAMES")
	{
		current_table.print_names();

	}
	else
	{
		std::cout << "Invalid Command. Please try again: " << std::endl;
	}
}

int main()
{
	welcome_message();
	bool running = true;
	Hashtable new_hashtable;
	//std::cout<<new_hashtable.hash_function("ABC")<< std::endl;
//	std::cout << new_hashtable.hash_function("AB") << std::endl;
	while (running)
	{
		menu_options();
		input_handler(new_hashtable, running);

	}

}