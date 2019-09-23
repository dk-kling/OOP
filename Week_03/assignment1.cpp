#include <iostream>

static const int rodata = 1;
int data = 1;
int bss;

int main() {
	int stack = 1;
	int* arr = new int[1];
	int* heap = arr;

	std::cout << "code\t" << (void*) main << std::endl;
	std::cout << "rodata\t" << (void*) rodata << std::endl;
	std::cout << "data\t" << &data << std::endl;
	std::cout << "bss\t" << &bss << std::endl;
	std::cout << "heap\t" << heap << std::endl;
	std::cout << "stack\t" << &stack << std::endl;
}
