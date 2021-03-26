#pragma once
#include "stock.h"
#include <fstream>
#include <stdio.h>
#include <errno.h>
#include <Windows.h> 
#include <cstdlib>

class Hashtable
{
//class-variables
private:

	//Datastructure for namesearch
	typedef struct s_name_search_data {
		int n_index_a_stocks;
		int n_collisions;
		//Constructors for the Datapoints of the namesearch
		s_name_search_data() :n_index_a_stocks(-1), n_collisions(0) {}
		s_name_search_data(int index, int collisions) :n_index_a_stocks(index), n_collisions(collisions) {}

	}name_search_data;

	int n_max_length; //of stocks
	int n_max_collisions_stocks;
	int n_max_collisions_name;
	name_search_data * a_name_search; 
	int n_amount_stocks;
	Stock * a_stocks;
	Stock *d_current_stock; //This can be used to access the last 
	enum error_type { exists, not_exist, import_not_found, import_error,no_data_found}; //extend this error list as needed and add an error msg in the error method
//Constructor
public:
	Hashtable()
		: n_max_length(find_next_prime(1000)), n_max_collisions_stocks(0),n_max_collisions_name(0), a_stocks(new Stock[n_max_length]), a_name_search(new name_search_data[n_max_length])
	{}
private:
//private-Methods
	int find_next_prime(int start_val)
	{
		bool divisible;
		for (int i = start_val;; i++)
		{
			divisible = false;
			for (int j = 2; j < i; j++)
			{
				if ((i % j) == 0)
				{
					divisible = true;
					break;
				}
			}
			if (!divisible)
				return i;
		}
	}
	bool create_stock(std::string& name, std::string& tag, std::string& wkn)
	{
		int collisions = 0;
		int names_collisions = 0;
		//create stock entry in stocks array
		int index_stocks_array = hash_function(tag);
		if (a_stocks[index_stocks_array].b_set) //collision! quadratic probing
			collisions = quadratic_probing_tag(index_stocks_array, tag)*(-1);
		quadratic_probing(index_stocks_array, collisions);
		Stock new_stock(name,tag,wkn,collisions,0);
		a_stocks[index_stocks_array] = new_stock;

		//Create Names search entry in names array	 
		int index_name_search = hash_function(name);
		if (a_name_search[index_name_search].n_index_a_stocks > 0) //collision! quadratic probing
			names_collisions = quadratic_probing_name(index_name_search, name)*(-1);
		quadratic_probing(index_name_search, names_collisions);
		s_name_search_data new_searchpoint(index_stocks_array, names_collisions);
		a_name_search[index_name_search] = new_searchpoint;

		//set current Stock to the last entry
		d_current_stock = &a_stocks[index_stocks_array];
		return true;
	}
	// Hash Function: H(s) = s[0]*(7^n-1)+ s[1] * (7^n-2) + ... + s[n-1]; n -> Length of string -1; Maybe we should increase the factor it is multiplied by in the hashfunction 
	int hash_function(std::string& s_stock_tag)
	{ 
		int n_hash_value = 0;
		for (int j = 0; j< s_stock_tag.length();j++)
		{
			int n_sum = (int)s_stock_tag[j];
			for (int i = 0; i < (s_stock_tag.length()-j); i++)
			{
				n_sum *= 7;
				n_sum %= n_max_length;
			}
			n_hash_value += n_sum;
			n_hash_value %= n_max_length;
		}
		return n_hash_value;
	}
	void quadratic_probing(int& n_hash_value, int& amount)
	{
		for (int i = 1; i <= amount; i++)
		{
			n_hash_value *= (i * i);
			n_hash_value %= n_max_length;
		}
	}

	//Hqp(s) = H(s) +sum(i^2, amount_of_collisions); Returns the index of the stocks array with the value and returns -1*amount of collisions if the value is not found 
	int quadratic_probing_tag(int& n_hash_value,std::string& stock_tag)
	{	
		int collisions = 1;
		int prev_hash_key = n_hash_value;
		for (int i = 1; i <= n_max_collisions_stocks; i++)
		{
			prev_hash_key += (i*i);
			prev_hash_key %= n_max_length;
			d_current_stock = &a_stocks[prev_hash_key];
			if (d_current_stock->s_tag.compare(stock_tag)==0)
				return prev_hash_key;
			collisions++;
		}
		return (-1)*collisions;
	}
	//returns index from a_names_search array which stores the index of the value found in the stocks array and -1*(amount of collisions) if the value is not found in the stocks array // NEEDS CHANGE
	int quadratic_probing_name(int& n_hash_value, std::string& stock_name)
	{
		int collisions = 1;
		int prev_hash_key = n_hash_value;
		int last_free_position=-1;
		int last_collision_amount = -1;

		for (int i = 1; i <= n_max_collisions_name; i++)
		{
			prev_hash_key += (i * i);
			prev_hash_key %= n_max_length;
			int index = a_name_search[prev_hash_key].n_index_a_stocks;
			if (index ==-1) // this will actually break if a stock in between is deleted. 
				break;
			d_current_stock = &a_stocks[index];
			if (d_current_stock->s_name.compare(stock_name) == 0)
				return prev_hash_key;
			collisions++;
		}
		if (collisions > n_max_collisions_name)
			n_max_collisions_name = collisions;
		return collisions*(-1);
	}

	//find_stock: returns true if the stock is found in the array, else false. the current_stock is set to the last search value
	bool find_stock_tag(std::string& stock_tag)
	{
		int hash_key = hash_function(stock_tag);
		d_current_stock = &a_stocks[hash_key];
		if (stock_tag.compare(d_current_stock->s_tag) == 0)
			return true;
		else
		{
			//Insert condition here to check if the amount of collisions is higher than the actual size of the hashtable
			hash_key = quadratic_probing_tag(hash_key, stock_tag);
			
			if (hash_key < 0)
				return false;
			
			d_current_stock = &a_stocks[hash_key];
			return true;
		}

	}
	//find_stock: returns true if the stock is found in the array, else false. the current_stock is set to the last search value
	bool find_stock_name(std::string& stock_name)
	{
		int hash_key = hash_function(stock_name);
		int name_indexvalue = a_name_search[hash_key].n_index_a_stocks;
		if (name_indexvalue == -1)
			return false;
		if (stock_name.compare(a_stocks[name_indexvalue].s_name)==0)
				return true;
		else
		{
			//Insert condition here to check if the amount of collisions is higher than the actual size of the hashtable
			hash_key = quadratic_probing_name(hash_key, stock_name);
			if (hash_key < 0)
				return false;
			
			d_current_stock = &a_stocks[hash_key];
			return true;

		}
	}
	
	void error(error_type error)
	{
		switch(error)
		{
			case exists:
				std::cout << "Error (1): Stock or Tag already exists!" << std::endl;
				break;
			case not_exist:
				std::cout << "Error (2): Stock or Tag not found." << std::endl;
				break;
			case import_not_found: 
				std::cout << "Error (3): CSV-File to import not found."<<std::endl;
				break;
			case import_error:
				std::cout << "Error (4): An Error occured during the import of the File." << std::endl;
				break;
			case no_data_found:
				std::cout << "Error (5): An Error occured during the import of the File." << std::endl;
				break;
		}
	}
	/*
	bool linear_search()
	{
		std::cout << "hello world";
	}*/
//functions of the hashtable
public:

	void print_table()
	{
		for (int i = 0; i < n_max_length; i++)
		{
			std::cout << i << " -> " << a_stocks[i].s_name << std::endl;
		}
	}
	void print_names()
	{
		for (int i = 0; i < n_max_length; i++)
		{
			std::cout << i << " -> " << a_name_search[i].n_index_a_stocks << std::endl;
		}
	}
	void to_upper(std::string& command) //As already said in the main, perhaps everything that has to do with the hashtable can be moved into this class 
	{
		for (int i = 0; i < command.length(); i++)
			command[i] > 90 ? command[i] = command[i] - 32 : command[i];

	}
	bool add()
	{
		std::string name = "";
		std::string tag = "";
		std::string wkn = "";
		
		std::cout << "What is the name of your new Stock?" << std::endl << ": ";
		std::cin >> name;
		to_upper(name);
		//Search if Stock Exists
		if (find_stock_name(name))
		{
			error(exists);
			return false;

		}
		std::cout << "Great! What's the stock tag?" << std::endl << ": ";
		std::cin >> tag;
		to_upper(tag);
		if (find_stock_tag(tag))
		{
			error(exists);
			return false;
		}
		std::cout << "Awesome, looks like you really found a new stock. Just enter the Unique stock ID, then we can move on. " << std::endl << ": ";
		std::cin >> wkn;
		to_upper(wkn);
		create_stock(name, tag, wkn);
		return true;
	}

	bool del()
	{
		std::cout << "Hello World! I am del" << std::endl;
		return true;
	}
	bool import_data()
	{
		std::string tag;
		std::cout << "Enter the Tag of the Stock you would like to add data to (the tag should be identical to the filename without \".csv\"-fileending)." << std::endl << ": ";
		std::cin >> tag;
		if (!find_stock_tag(tag))
		{
			error(not_exist);
			return false;
		}
		std::cout << "Stock found! Importing...";
		tag = tag + ".csv";
		/*
		FILE* csv_file;
		errno_t err;
		if ((err = fopen_s(&csv_file, tag.c_str(), "r")) != 0) {
			// File could not be opened. filepoint was set to NULL
			// error code is returned in err.
			// error message can be retrieved with strerror(err);

			// If your environment insists on using so called secure
			// functions, use this instead:
			char buf[10000];
			strerror_s(buf, sizeof buf, err);
			fprintf_s(stderr, "cannot open file '%s': %s\n",
				csv_file, buf);
		fopen_s(&csv_file,tag.c_str(),"r");
		}
		
		if (csv_file == nullptr)
		{
			error(import_not_found);
			return false;
		}*/
		if (d_current_stock->import_data(tag)) {
			std::cout << "Data imported!" << std::endl;
			return true;
		}
		error(import_error);
		return false;
	}
	bool search()
	{
		std::string choice;
		std::cout << "How do you want to search your Stock in the Hashtable? (N -> by Name, T -> by Tag)" << std::endl << ": ";
		while (42)
		{
			std::cin >> choice;
			to_upper(choice);
			if (choice.compare("N") == 0 || choice.compare("T")==0)
				break;
			std::cout << "Invalid input. Try again" << std::endl;
		}
		if (choice[0] == 'N')
		{
			std::cout << "Enter the name of your stock." << std::endl << ": ";
			std::cin >> choice;
			if (find_stock_name(choice))
			{
				std::cout << " Stock found! " << std::endl;
				if (d_current_stock->b_data)
				{
					auto values = d_current_stock->l_datavalues.end()--;
					std::cout << "Last Data: Date: " << values->s_date << ", Open: " << values->f_open << ", High: " << values->f_high 
						<< ", Close: " << values->f_close << ", Adjusted Close: " << values->f_adj_close << ", Volume: " << values->n_volume;
				}
				else
					std::cout << "Currently no Data available!" << std::endl;
			}
			else
				error(not_exist);
		}	
		if (choice[0] == 'T')
		{
			std::cout << "Enter the Tag of your stock." << std::endl << ": ";
			std::cin >> choice;
			if (find_stock_name(choice))
			{
				std::cout << " Stock found! " << std::endl;
				if (d_current_stock->b_data)
				{
					auto values = d_current_stock->l_datavalues.end()--;
					std::cout << "Last Data: Date: " << values->s_date << ", Open: " << values->f_open << ", High: " << values->f_high
						<< ", Close: " << values->f_close << ", Adjusted Close: " << values->f_adj_close << ", Volume: " << values->n_volume;
				}
				else
					std::cout << "Currently no Data available!" << std::endl;
			}
			else
				error(not_exist);
		}
		return true;
	}
	bool plot()
	{
		std::string tag;
		std::cout << "Enter the Stock Tag to plot the dedicated graph for it." << std::endl <<": ";
		std::cin >> tag;
		if (!find_stock_tag(tag))
		{
			error(not_exist);
			return false;
		}
		if (!d_current_stock->b_data)
		{
			error(no_data_found);
			return false;
		}
		float max = 0, min = 99999999999;
		//evaluate highest/smallest stock price
		for (int j = 0; j < d_current_stock->l_datavalues.size(); j++)
		{
			max = (d_current_stock->l_datavalues[j].f_high > max ? d_current_stock->l_datavalues[j].f_high : max);
			min = (d_current_stock->l_datavalues[j].f_low < min ? d_current_stock->l_datavalues[j].f_low : min);
		}
		float range = max - min;
		float unit = range / 25;
		for (int row = 0; row < 27; row++)
		{
			for (int col = 0; col < 60; col++)
			{
				if (col == 0)
				{
					if (row% 5==0)
					{
						float scale = max-(unit*row);
						char buf[1024];
						sprintf_s(buf, "%4.2f", scale);
						std::cout << std::string(buf) << " |";
					}
					else
						std::cout << "       |";
					

				}
					
				else if (row < 25)
				{
					float high_value = (float)(d_current_stock->l_datavalues[(int)(col/2)].f_close);
					float upper_range = max - high_value;
					if ((25-row)*unit <= upper_range)
						std::cout << "#";
					else
						std::cout << " ";
				}
				else if (row == 25)
					std::cout << "_";
				else if (row == 26)
				{
					if ((col % 20) - 2 == 0)
						std::cout << d_current_stock->l_datavalues[(int)(col / 2)].s_date;
					else if((col%20) <13)
						std::cout << " ";
				}
			}
			std::cout << std::endl;
		}


		return true;
	}

	bool save()
	{
		std::cout << "Hello World! I am save" << std::endl;
		return true;
	}
	bool load()
	{
		std::cout << "Hello World! I am load" << std::endl;
		return true;
	}
	bool quit()
	{
		//delete(a_stocks);
		//delete(a_name_search);
		exit(0);
	}
};
