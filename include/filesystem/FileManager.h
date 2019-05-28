#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "RandomFile.h"
#include "StaticHash.h"

class FileManager {
	std::string fileName;
	std::vector<std::vector<std::string>> parserCSV(std::string namefile);
	bool writeBinaryFile(const std::vector<std::vector<std::string>>&);
	bool readBinaryFile();
public:
	FileManager(std::string);
	bool search();
	bool insert(std::vector<std::string> row, int algorithmCode);
	void setFileName(std::string _filename);
};

FileManager::FileManager(std::string fileName)
	: fileName(fileName)
{
	std::string bin_name = fileName.substr(0, fileName.size()-3)+"bin";
	std::ifstream file(bin_name);
	bool is_open = file.is_open();
	file.close();
	if ( is_open ) return;
	std::vector<std::vector<std::string>> table = parserCSV(fileName);
	writeBinaryFile(table);
}

bool FileManager::writeBinaryFile(const std::vector<std::vector<std::string>>& data) {
	std::ofstream file;
	std::string bin_name = fileName.substr(0, fileName.size()-3)+"bin";
	int size;
	file.open(bin_name, std::ios::binary | std::ios::out | std::ios::trunc);
	for (int i = 0; i < data.size(); i++) {
		for (auto &el : data[i]) {
			size = el.size();
			file.write(reinterpret_cast<const char*>(&size), sizeof(int));
			file.write(el.data(), size);
		}
	}
	file.close();
	return true;
}

bool FileManager::readBinaryFile() {
	/*TODO*/
	return true;
}

std::vector<std::vector<std::string>> FileManager::parserCSV(std::string namefile) {
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

void FileManager::setFileName(std::string _filename){
	this->fileName=_filename;
}

// Parameters: 1 to insert with RandomFile, 2 to insert with Static Hash 
bool FileManager::insert(std::vector<std::string> row, int algorithmCode){
	RandomFile randomFile;
	StaticHash staticHash;
	switch(algorithmCode){
		case 1:
			randomFile.insert(row);
			break;
		case 2:
			break;
	}
	return false;
}

bool FileManager::search(){
	return 0;
}

#endif
