#include "String.h"

String::String(const std::string& str) {
	this->_val = str;
}

std::string String::val() {
	return this->_val;
}

void String::set_val(const std::string& str) {
	this->_val = str;
}

json_object* String::parse(const char* c, int length, char base) {
	int first = ++_index;
	std::string str = "";
	while (c[_index] != base) {
		str += c[_index++];
	}
	return new String(str);
}

json_object::_type String::type() {
	return this->STRING;
}

std::string String::to_string() {
	return this->val();
}
