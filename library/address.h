#pragma once
#include "../spring/interface.h"

class Address : public IAddress {
	std::string street;
	std::string city;
	std::string state;
	unsigned short zip;
public:
	Address(std::string street, std::string city, std::string state, unsigned int zip);
	virtual ~Address();
	void getAddress(std::ostream &o) const;
};

