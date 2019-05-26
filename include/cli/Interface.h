#include "../engine/DataManager.h"

class Interface{ 
    DataManager dataManager;

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
            dataManager.requestQuery(statement); 
            dataManager.executeQuery();
        }
    };
   

   void printLastQuery(){
        std::vector<std::string> queryVector = dataManager.accessQuery();
        std::cout<<queryVector[0]
                 <<" " + queryVector[1]
                 <<" FROM " << queryVector[2];
    };
    

    /* TODO
    void displayData(Table _table){
    
    }*/
};
