#include <map>
#include <vector>
#include <fstream>

typedef std::vector<std::string> Row;

class RandomFile{
    std::map<std::string, int> randomFileMap; 
    std::string fileName;

public:    
    RandomFile(){};
    
    RandomFile(std::string _filename){
        this->fileName = _filename;
        std::ifstream indexFile(fileName, std::ios::in, std::ios::binary);
        std::string 
        while(indexFile>>)
    };

    bool insert(Row row){
        // if key already exists return false, else insert
        std::string id;
        int position;
        randomFileMap[id] = position;

    };

    int search(){
       // Should return the position  
    }
};
