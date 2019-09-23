#include <iostream>

int main() {
	char target[] = "Seo SeongDeok";
	long b[011] = {2, 0, 1, 6, 0, 2, 0, 1, 1};
	int a = 17;
	int i = 99;
	int *c = new int[602];
	char * copy = "is no no";
	char name = 'a';

	std::cout << &name+i << std::endl;
	std::cout << "&target: " << &target << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "&a: " << &a << std::endl;
	std::cout << "&i: " << &i << std::endl;
	std::cout << "&c: " <<  &c << std::endl;
	std::cout << "&copy: " << &copy << std::endl;
}
