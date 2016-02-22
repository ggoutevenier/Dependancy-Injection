#include "../spring/bean.h"
#include "person.h"

Person :: Person(std::string firstName, std::string lastName, unsigned int age, Address &address) :
		firstName(firstName), lastName(lastName), age(age), address(address) {}
void Person::getPerson(std::ostream &o) const {
		o << firstName << " " << lastName << " " << age << std::endl;
		address.getAddress(o);
	}
Person::~Person(){}
namespace DataKinesis {
template<>
class Bean<Person> : public BeanBase<Person> {
	void construct() {
		if (!isConstructed()) {
			add(new Person(getValue<std::string>("first_name"), getValue<std::string>("last_name"), getValue<int>("age"),
				getRef<Address>("addr")));
		}
	}
public:
	Bean(const std::string &name, const IBean::Parameters &values, const IBean::Parameters &refs) : BeanBase(name, values, refs) {}
};
}
extern "C" 
	__declspec(dllexport) DataKinesis::IBean *makePerson(const std::string &name, const DataKinesis::IBean::Parameters &values, const DataKinesis::IBean::Parameters &refs) {
		return new DataKinesis::Bean<Person>(name,values,refs);
	}
