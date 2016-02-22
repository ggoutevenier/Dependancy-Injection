#pragma once
#include <iostream>
class IAddress {
public:
	virtual void getAddress(std::ostream &o) const = 0;
	virtual ~IAddress() {}
};

class IPerson {
public:
	virtual void getPerson(std::ostream &o) const = 0;
	virtual ~IPerson(){}
};
