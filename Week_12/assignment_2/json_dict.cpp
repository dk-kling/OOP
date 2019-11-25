#include "json_dict.h"

void json_dict::put (json_object* key, json_object* val) {
	if (this->find(key) == -1)
		this->v.push_back(std::make_pair(key, val));
	else
		this->v[this->find(key)].second = val;
}

int json_dict::find(json_object* key) {
	//std::vector<std::pair<json_object*, json_object*>>::iterator it;
	//for (it = v.begin(); it != v.end(); it++) {
	//	if (it->first == key)
	//		return 
	//}
	for (int i = 0; i < v.size(); i++) {
		if (this->v[i].first == key)
			return i;
	}
	return -1;
}

json_dict::json_dict() {
}

json_object* json_dict::parse(const char * c, int length) {
	
	int first = ++_index;
	json_object* first_val = nullptr;
	json_object* second_val = nullptr;
	json_dict* dict = nullptr;
	
	while(c[_index] != '}') {
		first_val = json_object::parse(c, length);
		if (c[_index] == ':') {
			_index++;
			second_val = json_object::parse(c, length);
		}
		dict->put(first_val, second_val);
		_index++;
	}
	return dict;
}

json_object* json_dict:: operator[](json_object* key) const {
	return nullptr;
}

json_object* json_dict:: operator[](const std::string& key) const {

	return nullptr;
}

json_object* json_dict:: operator[](int key) const {

	return nullptr;
}

json_object::_type json_dict::type() {
	return this->DICT;
}

std::string json_dict::to_string() {
	std::string str = "{";
	for (int i = 0; i < v.size(); i++) {
		str += this->v[i].first->to_string() + ", " + v[i].second->to_string();
	}
	str += "}";
	return str;
}
