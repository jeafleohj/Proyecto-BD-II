#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/cli/Interface.h"
#include "../include/filesystem/FileManager.h"
#include "../include/filesystem/StaticHash.h"

using namespace std;

int main(){
    Interface interface;
    DataManager dataManager;
	FileManager fm("files/DEMOGRAPHICS.csv");
	StaticHash sh("files/DEMOGRAPHICS.bin");
    // while(true){
    //     interface.displayMenu();
    //     std::string statement, column, adverb, table;
    //     interface.requestQuery(statement,column,adverb,table);
    //     dataManager.receiveQuery(statement, column, adverb, table);
    //     dataManager.executeQuery();

    // }

    return 0;
}
