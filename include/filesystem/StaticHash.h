#ifndef STATICHASH_H
#define STATICHASH_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
//https://catalog.data.gov/dataset/u-s-electric-utility-companies-and-rates-look-up-by-zipcode-2015-8c84b
class StaticHash {
	std::string index;
	std::vector<std::vector<std::string>> loadBinaryFile(std::string);
	bool generateIndex(std::string);
public:
	StaticHash() {};
	StaticHash(std::string);
};

StaticHash::StaticHash(std::string binfile) {
	index = binfile.substr(0,binfile.size()-3)+"hi";
	std::ifstream file(index);
	bool is_open = file.is_open();
	file.close();
	if ( is_open ) return;
	generateIndex(binfile);
}

std::vector<std::vector<std::string>> StaticHash::loadBinaryFile(std::string biname) {
	std::ifstream bf(biname, std::ios::binary | std::ios::in);
	std::vector<std::vector<std::string>> data;
	std::vector<std::string> row;
	int n_col,size;
	bf.read((char*)(&n_col), sizeof(int));
	row.resize(n_col);
	while (!bf.eof()) {
		for(int i = 0; i<n_col; ++i) {
			bf.read((char*)(&size), sizeof(int));
			row[i].resize(size, ' ');
			bf.read(row[i].data(), size);
		}
		data.push_back(row);
	}
	return data;
}

bool StaticHash::generateIndex(std::string binfile) {
	std::vector<std::vector<std::string>> table = loadBinaryFile(binfile);
	
	return true;
} 

#endif
