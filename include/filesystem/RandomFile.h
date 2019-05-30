#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>

typedef std::vector<std::string> Row;

class RandomFile{
    public:

    std::map<std::string, int> randomFileMap; 
    std::string indexFile;
   
    RandomFile(){};
    
    RandomFile(std::string &_filename){
        this->indexFile = "../include/filesystem/data/RandomFile/index" 
                          + _filename.substr(7, _filename.length()-10) + "rf";
        
        std::fstream rfFile(indexFile, std::ios::in);
        
        if(rfFile.is_open()){
            std::string id; int position;
            while(rfFile>>id>>position){ 
                randomFileMap[id] = position; 
            }
            rfFile.close();
        }
        else{
            std::ofstream rfFile(indexFile, std::ios::out);
            std::fstream input(_filename);
            if(input.is_open()){
                std::string id;
                std::getline(input, id);
                int position = id.length()+1;
                while(std::getline(input,id,',')){
                    randomFileMap[id] = position;
                    rfFile<<id<<' '<< position <<'\n';
                    position += id.length()+1;
                    std::getline(input, id);
                    position += id.length()+1;
                }
            }
            input.close();
            rfFile.close();
        } 
    };

    bool insert(Row row){
        // if key already exists return false, else insert
        std::string id;
        int position;
        randomFileMap[id] = position;
    };

    int search(std::string id){
       // Should return the position
       return randomFileMap[id];
    }
};
