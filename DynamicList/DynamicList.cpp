#include <iostream>
#include <cstdlib>
#include "LinkedList.h"

int main() {
	DynamicList<int> list;
	list.addEnd(5);
	list.addEnd(10);
	list.addStart(0);
	list.removeat(1);
	std::cout << list.at(1) << std::endl;
}


