#include "Query.h"
#include "../filesystem/FileManager.h"

class DataManager{
    Query query; 
public:

    DataManager(){};

    DataManager(Query _query){
        this->query = _query;
    };

    void receiveQuery(std::string &_statement, std::string &_column, 
                      std::string &_adverb, std::string &_table){
        query.setQuery(_statement, _column, _adverb, _table);
    }

    void executeQuery(){
        std::string statement = query.getQuery()[0];
        if(statement == "SELECT"){ 
            FileManager fm;
            std::string filename = query.getQuery()[3]+".csv"; 
            fm.setFileName(filename); 
            std::cout<<fm.search(1, query.getQuery()[1])<<'\n';
        }
        else if(statement == "INSERT"){
            std::cout<<"executing a INSERT query\n";
            
        }
        else if(statement == "DELETE"){
            std::cout<<"executing a DELETE query\n";
        }
        else if(statement == "COPY"){
            std::cout<<"Loading a csv file\n";
            std::string filename = query.getQuery()[3];
            //FileManager fileManager;
            // fileManager.readCSV(filename);
        }
        else{
            std::cout<<"No match with statement "<<statement<<'\n'; 
        }
    };

    std::vector<std::string> accessQuery(){
        return query.getQuery();
    }
};
