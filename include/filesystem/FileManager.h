#include <iostream>

class FileManager{

public:
    FileManager(){};
    
    void readCSV(std::string filename){
        std::cout<<"Reading " << filename<<'\n';      
    } 
};
