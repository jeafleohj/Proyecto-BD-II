#include "Response.h"
#include "../engine/DataManager.h"

class Interface{
    Query query;
    Response response;

public:
    Interface(){};
    void displayMenu(){
        std::cout<<"utecDB=# ";
        std::string statement;
        std::cin>>statement;
        if(statement == "exit"){
             exit(EXIT_SUCCESS);
        }
        else{
            requestQuery(statement);
            DataManager dataManager(query);
            dataManager.executeQuery();           
        }
        
    };
    
    void requestQuery(std::string &_statement){
            std::string column, table;
            std::cin>>column>>table>>table;
            query.setQuery(_statement, column, table);
    };

    void printLastQuery(){
        std::vector<std::string> queryVector = query.getQuery();
        std::cout<<queryVector[0]
                 <<" " + queryVector[1]
                 <<" FROM " << queryVector[2];
    };

    /* TODO
    void displayData(Table Table){
    
    }*/
};
