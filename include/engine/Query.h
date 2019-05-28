#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <algorithm>

class Query{
    std::string statement;
    std::string column;
    std::string adverb;
    std::string table;

public: 
    Query(){};
    
    void setQuery(std::string &_statement, std::string &_column, 
                  std::string &_adverb,std::string &_table){
        this->statement = _statement;
        this->adverb = _adverb;
        this->column = _column;
        this->table = _table;
    };

    std::vector<std::string> getQuery(){
        std::vector<std::string> queryVector{this->statement, this->column, this->adverb, this->table};
        return queryVector;
    };

};
