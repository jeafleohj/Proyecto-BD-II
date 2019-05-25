/*
 * file: main.cpp
 * author: Jhony Angulo
 * date: 25-05-2019
 */
#include <fstream>
#include "functions.hpp"
std::vector<std::vector<std::string>> parserCSV(std::string namefile) {
	std::string line;
	std::ifstream file(namefile);
	getline(file,line);
	int n_fields=0;
	std::vector<std::vector<std::string>> data;
	int initial_position;
	bool is_string;
	while(getline(file,line)) {
		std::vector<std::string> row;
		initial_position = 0;
		is_string = false;
		for(int i=0; i<line.size(); i++) {
			if( line[i] == '\"' ) is_string = !is_string;
			if( !is_string && line[i] == ',' ) {
				row.push_back( line.substr(initial_position, i-initial_position));
				initial_position = i+1;
			}
		}
		data.push_back(row);
	}
	file.close();
	return data;
}
