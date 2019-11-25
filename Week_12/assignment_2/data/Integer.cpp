//201602011 서성덕

#include "Integer.h"

Integer::Integer(int value) {
	this->_val = value;
}

int Integer::val() {
	return this->_val;
}

void Integer::set_val(const int& value) {
	this->_val = value;
}

json_object* Integer::parse(const char* c, int length) {
	int first = _index;
	std::string str = "";
	while (c[_index] >= '0' && c[_index] <= '9') {
		str += c[_index++];
	}
	_index--;
	return new Integer(std::stoi(str));
}

json_object::_type Integer::type() {
	return this->INT;
}

std::string Integer::to_string() {
	return std::to_string(this->val());
}
