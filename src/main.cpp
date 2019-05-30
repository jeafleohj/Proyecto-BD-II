#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/cli/Interface.h"
using namespace std;

int main(){
    Interface interface;
    DataManager dataManager;
    
    while(true){
        interface.displayMenu();
        std::string statement, column, adverb, table;
        interface.requestQuery(statement,column,adverb,table);
        dataManager.receiveQuery(statement, column, adverb, table);
        dataManager.executeQuery();
    }

    return 0;
}
