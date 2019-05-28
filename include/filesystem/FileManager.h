#include <iostream>
#include <fstream>
#include "RandomFile.h"
#include <vector>

typedef std::vector<std::string> Row;

class FileManager{
    std::string fileName;

public:
    
    FileManager(){
        
    };

    void setFileName(std::string _filename){
        this->fileName=_filename;
    }

    bool readCSV(std::string _filename){
        std::cout<<"Reading " << _filename<<'\n';
        
        std::string line;
	std::ifstream file(_filename, std::ios::in);
	getline(file,line);
	int n_fields=0;	
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
    };

    // Parameters: 1 to insert with RandomFile, 2 to insert with Static Hash 
    bool insert(int algorithmCode{
       switch(algorithmCode){
            case 1:
                RandomFile randomFile;
                randomFile.insert(Row row);
                break;
            case 2:
                StaticHash staticHash;
        }

    }

    bool search(){
        
    }
};
