#include "json_list.h"

json_list::json_list() {

}

json_object* json_list::parse(const char * c, int length) {
	int first = ++_index;
	json_object* val = nullptr;
	json_list* list = nullptr;
	while(c[_index] != ']') {
		val = val->parse(c, length);
		list->v.push_back(val);
		if (c[_index] == ',') {
			val = val->parse(c, length);
			list->v.push_back(val);
		}
		_index++;
	}
}

json_object* json_list::operator[] (int key) const {
	return nullptr;
}

json_object::_type json_list::type() {
	return this->LIST;
}

std::string json_list::to_string() {
	std::string str = "[";
	for (int i = 0; i < v.size(); i++) {
		if (i != 0 && i != v.size()-1)
			str += ", ";
		str += v[i]->to_string();
	}
	str += "]";
	return str;
}
