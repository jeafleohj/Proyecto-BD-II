#include "Query.h"
#include "Response.h"

class DataManager{
    Query query;
    Response response;

public:

    DataManager(){};

    DataManager(Query _query){
        this->query = _query;
    };

    void requestQuery(std::string &_statement){
        std::string column, adverb, table;
        std::cin>>column>>adverb>>table;
        query.setQuery(_statement, column, adverb, table);
    }

    void executeQuery(){
        if(query.getQuery()[0]=="SELECT"){
            std::cout<<"executing a select query\n";

        }
        else if(query.getQuery()[0]=="INSERT"){
            std::cout<<"executing a INSERT query\n";
        }
        else if(query.getQuery()[0]=="DELETE"){
            std::cout<<"executing a DELETE query\n";
        }
        else if(query.getQuery()[0]=="COPY"){
            std::cout<<"Loading a csv file\n";
        }
        else{
            std::cout<<"No match with statement "<<query.getQuery()[0]<<'\n';
        }
    };

    std::vector<std::string> accessQuery(){
        return query.getQuery();
    }
};
