#include "../engine/DataManager.h"
#include <algorithm>

class Interface{ 
public:
    Interface(){};
    void displayMenu(){
        std::cout<<"utecDB=# ";
    };
    
    void requestQuery(std::string &_statement, std::string &_column, 
                      std::string &_adverb, std::string &_table){
        std::cin>>_statement;
        std::transform(_statement.begin(), _statement.end(), _statement.begin(), ::toupper);

        if(_statement == "EXIT")
            exit(EXIT_SUCCESS);
        std::cin>>_column>>_adverb>>_table;
        
    }

    


    /* TO FIX
    void printLastQuery(){
        std::vector<std::string> queryVector = dataManager.accessQuery();
        std::cout<<queryVector[0]
                 <<" " + queryVector[1]
                 <<" FROM " << queryVector[2];
    };
    */

    void displayData(Table _table){
        //TODO
    }
};
