#ifndef COLUMN_H
#define COLUMN_H
#include <string>
class Column {
	typedef std::string string;
	string name;
	string data_type;
	int data_length;
	bool is_null;
	bool is_pk;
 public:
	Column(std::string, std::string, int, bool, bool);
	Column(const Column&);
	~Column() {};
	string getName() const;
	string getDataType() const;
	int getDataLength() const;
	bool getIsNull() const;
	bool getIsPK() const;
	friend std::ostream& operator<<(std::ostream& os, const Column& d);
};

Column::Column(string name, string data_type, int data_length=10, bool is_null=false, bool is_pk=false)
	: name(name),
	  data_type(data_type),
	  data_length(data_length),
	  is_null(is_null),
	  is_pk(is_pk)
{}

Column::Column(const Column &c)
	: Column(c.name, c.data_type, c.data_length, c.is_null, c.is_pk)
{}

Column::string Column::getName() const{
	return name;
}

Column::string Column::getDataType() const{
	return data_type;
}

int Column::getDataLength() const{
	return data_length;
}

bool Column::getIsNull() const
{
	return is_null;
}

bool Column::getIsPK() const{
	return is_pk;
}

std::ostream &operator<<(std::ostream &os, const Column &col) {
	os << col.getName() << " "
	   << col.getDataType() << " "
	   << std::to_string(col.getDataLength()) << " "
	   << std::to_string(col.getIsNull()) << " "
	   << std::to_string(col.getIsPK());
	return os;
}
#endif
