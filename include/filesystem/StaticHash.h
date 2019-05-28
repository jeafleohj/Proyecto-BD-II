#ifndef STATICHASH_H
#define STATICHASH_H
#include <string>
#include <vector>
#include <iostream>
//https://catalog.data.gov/dataset/u-s-electric-utility-companies-and-rates-look-up-by-zipcode-2015-8c84b
class StaticHash {
	std::string index;
	bool generateIndex();
public:
  StaticHash() {};
  StaticHash(std::string);
};

StaticHash::StaticHash(std::string binfile) {
	std::string index_name =binfile.substr(0,binfile.size()-3)+"hi";
	std::cout << index_name << "\n";
}

bool StaticHash::generateIndex() {
	
	return true;
} 

#endif
