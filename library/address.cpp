#include "address.h"
#include "../spring/bean.h"

Address::Address(std::string street, std::string city, std::string state, unsigned int zip) :
		street(street), city(city), state(state), zip(zip) {}
	void Address::getAddress(std::ostream &o) const {
		o << street << std::endl;
		o << city << ", " << state << " " << zip << std::endl;
	}
Address::~Address() {}
namespace DataKinesis {
template<>
class Bean<Address> : public BeanBase<Address> {
	void construct() {
		if (!isConstructed()) {
			add(new Address(
				getValue<std::string>("street"),
				getValue<std::string>("city"),
				getValue<std::string>("state"),
				getValue<unsigned short>("zip")
				));
		}
	}
public:
	Bean(const std::string &name, const IBean::Parameters &values, const IBean::Parameters &refs) : BeanBase(name, values, refs) {}
};
}
extern "C"
__declspec(dllexport) DataKinesis::IBean *makeAddress(const std::string &name, const DataKinesis::IBean::Parameters &values, const DataKinesis::IBean::Parameters &refs) {
	return new DataKinesis::Bean<Address>(name, values, refs);
}
