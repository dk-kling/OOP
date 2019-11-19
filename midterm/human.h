//
// Created by 김혁진 on 2019/10/28.
//

#ifndef SMART_PTR_HUMAN_H
#define SMART_PTR_HUMAN_H
#include <string>
#include <iostream>
class human {
	private:
		char* name;
	public:
		human();
		explicit human(char* name);
		char* get_name();
		virtual int get_id();
};

#endif //SMART_PTR_HUMAN_H
