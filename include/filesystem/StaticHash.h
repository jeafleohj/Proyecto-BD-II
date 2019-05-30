#ifndef STATICHASH_H
#define STATICHASH_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>


class StaticHash {
	std::string index;
	std::string binfile;
	std::map<int, std::vector<int>> ht;
	std::vector<std::vector<std::string>> loadBinaryFile(std::string, std::map<int,int>&);
	void generateIndex(std::string);
	bool writeIndex(std::map<int, std::vector<int>>);
	void readIndex();
public:
	StaticHash() {};
	StaticHash(std::string);
	void search(int value);
};

StaticHash::StaticHash(std::string binfile)
	: binfile(binfile)
{
	index = binfile.substr(0,binfile.size()-3)+"hi";
	std::ifstream file(index);
	bool is_open = file.is_open();
	file.close();
	//if ( is_open ) return;
	generateIndex(binfile);
}

std::vector<std::vector<std::string>> StaticHash::loadBinaryFile(std::string biname, std::map<int,int>& pk) {
	std::ifstream bf(biname, std::ios::binary | std::ios::in);
	std::vector<std::vector<std::string>> data;
	std::vector<std::string> row;
	int n_col,size;
	bf.read((char*)(&n_col), sizeof(int));
	row.resize(n_col);
	int pos;
	while (!bf.eof()) {
		pos = bf.tellg();
		for(int i = 0; i<n_col; ++i) {
			bf.read((char*)(&size), sizeof(int));
			row[i].resize(size, ' ');
			bf.read(row[i].data(), size);
			if(i==0) {
				pk[std::stoi(row[i])] = pos;
			}
		}
		data.push_back(row);
	}
	data.pop_back();
	return data;
}

bool StaticHash::writeIndex(std::map<int, std::vector<int>> ht) {
	std::ofstream ibf(index, std::ios::binary | std::ios::out);
	int size;
	for (auto i : ht) {
		size=i.second.size();
		ibf.write(reinterpret_cast<const char*>(&i.first), sizeof(int));
		ibf.write(reinterpret_cast<const char*>(&size), sizeof(int));
		for (auto j : i.second) {
			ibf.write(reinterpret_cast<const char*>(&j), sizeof(int));
		}
	}
	return true;
}

void StaticHash::readIndex() {
	std::map<int, std::vector<int>> ht;
	std::ifstream ibf(index, std::ios::binary | std::ios::in);
	int value,key,n_el;
	while (!ibf.eof()) {
		ibf.read((char*)(&key), sizeof(int));
		ibf.read((char*)(&n_el), sizeof(int));
		for (int i = 0; i < n_el; i++) {
			ibf.read((char*)(&value), sizeof(int));
			ht[key].push_back(value);
		}
	}
}

void StaticHash::generateIndex(std::string binfile) {
	std::map<int,int> pk;
	std::vector<std::vector<std::string>> lbf = loadBinaryFile(binfile,pk);
	for(auto &i:pk){
		ht[((i.first<<7)%101101)].push_back(i.second);
	}
}


void StaticHash::search(int value) {
	std::ifstream bin(binfile, std::ios::binary | std::ios::in);
	std::vector<std::string> data ;
	int size;
	bin.read((char*)(&size), sizeof(int));
	bin.seekg(ht[(value<<7)%101101][0], std::ios::beg);
	data.resize(size);
	for (int i = 0; i < data.size(); i++) {
		bin.read( (char*)(&size), sizeof(int) );
		data[i].resize(size);
		bin.read( data[i].data(), size);
	}
	for(auto i : data) {
		std::cout << i << " ";
	}
	std::cout << "\n";
	bin.close();
}
#endif
