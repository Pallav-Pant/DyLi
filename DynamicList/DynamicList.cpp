#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

int main() {
	DynamicList<int> list;
	list.addEnd(10);
	list.addEnd(20);
	list.addEnd(30);
	list.addEnd(40);
	list.addEnd(50);
	list.addEnd(60);
	list.addEnd(70);
	list.addStart(0);
	std::cout << list.at(-2) << std::endl;
	list.removeEnd();
	list.removeStart();
	std::cout << list.at(0) << std::endl;
	std::cout << list.at(-2) << std::endl;

}


