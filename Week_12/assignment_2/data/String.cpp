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
	//std::string str = " ";
	std::string str = "\'";
	while (c[_index] != base) {
		str += c[_index++];
	}
	//std::string dest = str.substr(1, str.size());
	str += "\'";
	return new String(str);
	//return new String(dest);
}

json_object::_type String::type() {
	return this->STRING;
}

std::string String::to_string() {
	//std::string str = "\'" + this->val() + "\'";
	//return str;
	return this->val();
}
