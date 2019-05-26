#include "../cli/Query.h"

class DataManager{
    Query query;
public:
    DataManager(Query _query){
        this->query = _query;
    };
    void executeQuery(){
        std::vector<std::string> queryVector=query.getQuery();
        if(queryVector[0]=="SELECT"){
            std::cout<<"executing a select query\n";
        }
        else if(query.getQuery()[0]=="INSERT"){
            
        }
        else if(query.getQuery()[0]=="DELETE"){
        
        }
    };
};
