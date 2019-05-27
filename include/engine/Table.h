#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include "Column.h"
#include "Row.h"

class Table{
	using string = std::string;
	std::string name;
	std::vector<Column> columns;
	std::vector<Row> rows;
public:
	Table(string name, int n_colums, std::vector<Column>);
	//Asumire que se mantiene el orden
	void insertRow(std::vector<std::string>, int);
	friend std::ostream& operator<<(std::ostream&, const Table&);
};

void Table::insertRow(std::vector<std::string> values, int index) {
	rows.emplace_back(columns, values, index);
}

std::ostream& operator<<(std::ostream& os, const Table& table)
{
	for (int i = 0; i < table.rows.size(); i++) {
		for (auto &c : table.columns) {
			os<< table.rows[i].getColumnValue(c)<<" ";
		}
	}
	return os;
}

#endif
