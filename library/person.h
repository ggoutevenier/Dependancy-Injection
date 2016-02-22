#pragma once
#include "../spring/interface.h"
#include "address.h"

class Person : public IPerson {
	std::string firstName;
	std::string lastName;
	unsigned int age;
	Address &address;
public:
	Person(std::string firstName, std::string lastName, unsigned int age, Address &address);
	virtual ~Person();
	void getPerson(std::ostream &o) const;
};


