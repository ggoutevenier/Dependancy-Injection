//#include "spring.h"
#include <iostream>
#include "interface.h"
#include "applicationcontext.h"
#include <boost/algorithm/string.hpp>

using namespace DataKinesis;

int main() {
	try {
		ApplicationContext context("C:\\Users\\Gerard\\workspace\\spring\\springGCC.xml");

		IPerson &person = context.get<IPerson>("Joe");
		person.getPerson(std::cout);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
