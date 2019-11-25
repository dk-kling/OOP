#include "json_list.h"

json_list::json_list() {

}

json_object* json_list::parse(const char * c, int length) {
	
	json_object* val = nullptr;
	json_list* list = new json_list();
	_index++;

	while(c[_index] != ']') {
		if(c[_index] == ',' || c[_index] == ' ') {
			_index++;
			continue;
		}
		json_object* val = json_object::parse(c, length);
		list->v.push_back(val);
		
		_index++;
	}
	return list;
}

json_object* json_list::operator[] (int key) const {
	return this->v[key];
}

json_object::_type json_list::type() {
	return this->LIST;
}

std::string json_list::to_string() {
	std::string str = "[";
	for (int i = 0; i < v.size(); i++) {
		if (i != 0 && i != v.size())
			str += ", ";
		str += v[i]->to_string();
	}
	str += "]";
	return str;
}
