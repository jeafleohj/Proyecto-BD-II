#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include "Query.h"
#include "Table.h"
#include "../filesystem/FileManager.h"

class DataManager{
    Query query;
    //Table table;
public:
	DataManager();
	DataManager(Query);
	void receiveQuery(std::string &_statement, std::string &_column, 
					  std::string &_adverb, std::string &_table);
	void executeQuery();
	std::vector<std::string> accessQuery();
};

DataManager::DataManager(){
	
};

DataManager::DataManager(Query _query){
	this->query = _query;
};

void DataManager::receiveQuery(std::string &_statement, std::string &_column, 
				  std::string &_adverb, std::string &_table){
	query.setQuery(_statement, _column, _adverb, _table);
}

void DataManager::executeQuery(){
	std::string statement = query.getQuery()[0];
	if(statement == "SELECT"){
		std::cout<<"executing a "<<statement<< "query\n";
        
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
		FileManager fileManager(filename);
	}
	else{
		std::cout<<"No match with statement "<<statement<<'\n'; 
	}
};

std::vector<std::string> DataManager::accessQuery(){
	return query.getQuery();
}

#endif
