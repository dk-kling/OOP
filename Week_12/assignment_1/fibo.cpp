#include <iostream>

int fibo(int i) {
	//if (i < 0) {
	//	std::cout << "i < 0" << std::endl;
	//	return 0;
	//}
	if (i <= 1) {
		return i;
	}
	else {
		return (fibo(i-1) + fibo(i-2));
	}
}

int main() {
	int i;
	std::cin >> i;
	int val = fibo(i);

	std::cout << val << std::endl;
	return 0;
}
