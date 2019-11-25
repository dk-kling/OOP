//201602011 서성덕

#include "json_object.h"
#include "json_dict.h"
#include "json_list.h"
#include "data/String.h"
#include "data/Integer.h"

int json_object::_index = 0;

json_object* json_object::parse(const char* c, int length) {
	while(c[_index] != '\0') {
		if (c[_index] == '{') {
			return json_dict::parse(c, length);
		}
		else if (c[_index] == '[') {
			return json_list::parse(c, length);
		}
		else if (c[_index] == '"') {
			return String::parse(c, length, '"');
		}
		else if (c[_index] == '\'') {
			return String::parse(c, length, '\'');
		}
		else if (c[_index] >= '0' && c[_index] <= '9') {
			return Integer::parse(c, length);
		}
		_index++;
	}
}

json_object* json_object::parse(const std::string& str) {
	const char *c = str.c_str();
	_index = 0;
	json_object::parse(c, str.size());
}
