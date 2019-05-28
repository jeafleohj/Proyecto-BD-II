#include <iostream>
#include <fstream>
#include "RandomFile.h"
#include "DynamicHash.h"
#include <vector>

class FileManager{
    std::string fileName;
    

public:
    
    FileManager(){
        
    };

    void setFileName(std::string _filename){
        this->fileName=_filename;
    }

    bool readCSV(std::string _filename){
            
    };

    // Parameters: 1 to insert with RandomFile, 2 to insert with Static Hash 
    bool insert(Row row, int algorithmCode){
       switch(algorithmCode){
           case 1:
               RandomFile randomFile;
               return randomFile.insert(Row row);
               break;
           case 2:
               StaticHash staticHash;
        }

    }

    bool search(){
        
    }
};
