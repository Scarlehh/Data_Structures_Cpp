#include "HashTable.h"
#include <iostream>

int main() {
	HashTable<int> table(3);
	table.add(5);
	table.add(4);
	table.add(3);
	table.add(2);
	table.add(1);
	table.add(0);
	std::cout << table << "\n";
	return 0;
}
