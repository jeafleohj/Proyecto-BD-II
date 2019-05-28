#ifndef ROW_H
#define ROW_H

#include <string>
#include <map>
#include <vector>
#include "Column.h"

class Row
{
	int index;
	std::map<std::string, std::string> data;
public:
	Row(const std::vector<Column>&, std::vector<std::string>, int);
	Row(const std::vector<std::pair<Column, std::string>> &, int);
	void updateData(const Column&, const std::string&);
	std::string getColumnValue(Column);
	friend std::ostream& operator<<(std::ostream& os, const Row& c);
};

Row::Row(const std::vector<Column>& columns, std::vector<std::string> value, int index = 0)
	: index(index)
{
	for (int i = 0; i < columns.size(); i++) {
		data[columns[i].getName()] = value[i];
	}
}

Row::Row(const std::vector<std::pair<Column, std::string>>& data, int index)
	: index(index)
{
	for (auto &el : data) {
		this->data[el.first.getName()] = el.second;
	}
}

void Row::updateData(const Column& c, const std::string &value) {
	if (value == "" && !c.getIsNull())
		//error: cant be null
		return; 
	if (!data.count(c.getName()))
		//error: no column
		return;
	data[c.getName()] = value;
}

std::string Row::getColumnValue(Column c) {
	if( !data.count(c.getName()) )
		//error: no column
		return "";
	return data[c.getName()];
}

std::ostream &operator<<(std::ostream &os, const Row &c) {
	for (auto &el : c.data) {
		os<<el.second<<" ";
	}
	return os;
}

#endif
