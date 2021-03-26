#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#pragma once

class Stock
{
public:
	typedef struct data {
		std::string s_date;
		float f_open;
		float f_high;
		float f_low;
		float f_close;
		float f_adj_close;
		unsigned n_volume;
	}data;
	//Members
	std::string s_stock_number;
	std::string s_tag;
	std::string s_name;
	int n_collision_value;
	std::vector<data> l_datavalues;
	bool b_set;
	bool b_data;
	int n_dataamount;
	//Constructor
	Stock()
		:s_stock_number(), s_tag(), s_name(), n_collision_value(0), l_datavalues(), b_set(false), b_data(false),n_dataamount(0)
	{}

	Stock(std::string name, std::string tag, std::string stock_number, int collisions, int load_data_amount) :
		s_stock_number(stock_number), s_tag(tag), s_name(name), n_collision_value(collisions), l_datavalues(),b_set(true), b_data(false),n_dataamount(0)
	{
		//insert loop here to load the data or call the function below? idk 
	}

	bool import_data(std::string filename) //no error handling here. maybe during reading there could be an error handler or smth.
	{
		n_dataamount = 0;
		b_data = true;
		data datapoint;
		FILE* csv_file;
		fopen_s(&csv_file, filename.c_str(),"r");
		std::vector<std::string> row;
		std::string line, word, temp;
		std::ifstream fin;
		fin.open(filename.c_str(),std::ios::in);
		bool headings = true;
		while (fin >> temp)
		{
			row.clear();
			data datapoint;
			std::getline(fin, line);
			if (headings)
			{
				headings = false;
				continue;
			}
			std::stringstream x(temp);
			while (std::getline(x, word, ','))
			{
				row.push_back(word);
			}
			datapoint.s_date = row[0];
			datapoint.f_open = std::stof(row[1]);
			datapoint.f_high = std::stof(row[2]);
			datapoint.f_low = std::stof(row[3]);
			datapoint.f_close = std::stof(row[4]);
			datapoint.f_adj_close = std::stof(row[5]);
			datapoint.n_volume = std::stoi(row[6]);

		/*
			//why does this not work?
			//char* date[11];
			//bool heading = true;
			//fscanf_s(csv_file, "%s,%lf,%lf,%lf,%lf,%lf,%u");
			if (heading)
			{
				fscanf_s(csv_file, "%s");
			}
			fscanf_s(csv_file, "%10s,%lf,%lf,%lf,%lf,%lf,%u\n", &datapoint.f_open, &datapoint.f_high, &datapoint.f_low, &datapoint.f_close, &datapoint.f_adj_close, &datapoint.n_volume);
			*/
			


			l_datavalues.push_back(datapoint);
			n_dataamount++;
			if (n_dataamount > 30)
			{
				l_datavalues.erase(l_datavalues.begin());
				n_dataamount--;
			}
		}
		return true;
	}


};

