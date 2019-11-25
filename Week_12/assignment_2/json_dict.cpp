#include "json_dict.h"

void json_dict::put (json_object* key, json_object* val) {
	int num = this->find(key);
	if (num == -1)
		this->v.push_back(std::make_pair(key, val));
	else
		this->v[num].second = val;
}

int json_dict::find(json_object* key) {
	for (int i = 0; i < v.size(); i++) {
		if (key->to_string() == v[i].first->to_string())
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
	json_dict* dict = new json_dict();
	
	
	while(c[_index] != '}') {
		if (c[_index] == ',') {
			_index++;
		}

		json_object* first_val = json_object::parse(c, length);
		while (c[_index] != ':') {
			_index++;
		}
		_index++;

		second_val = json_object::parse(c, length);

		dict->put(first_val, second_val);

		_index++;
		
	}
	return dict;
}

json_object* json_dict:: operator[](json_object* key) const {
	for (int i = 0; i < v.size(); i++) {
		if (key->to_string() == v[i].first->to_string())
			return this->v[i].second;
	}
	return nullptr;
}

json_object* json_dict:: operator[](const std::string& key) const {
	for (int i = 0; i < v.size(); i++) {
		if (key == v[i].first->to_string())
			return this->v[i].second;
	}
	return nullptr;
}

json_object* json_dict:: operator[](int key) const {
	for (int i = 0; i < v.size(); i++) {
		if (std::to_string(key) == v[i].first->to_string())
			return this->v[i].second;
	}
	return nullptr;
}

json_object::_type json_dict::type() {
	return this->DICT;
}

std::string json_dict::to_string() {
	std::string str = "{";
	for (int i = 0; i < v.size(); i++) {
		if (i != 0 && i != v.size())
			str += ", ";
		str += this->v[i].first->to_string() + ": " + v[i].second->to_string();
		//if (i != 0 && i != v.size())
		//	str += ", ";
	}
	str += "}";
	return str;
}
