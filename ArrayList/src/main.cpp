#include <iostream>
#include "ArrayList.h"

int main() {
	char arr[3] = {'a', 'b', 'c'};
	ArrayList<char> list(arr, 3);
	std::cout << list.remove(4) << "\n";
	list.add('d');
	list.add('d');
	std::cout << list << "\n";
	list.removeAll('d');
	return 0;
}
