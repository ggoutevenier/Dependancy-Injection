#pragma once
#include <string>
#include <memory>
#include <map>
#include <exception>
#include <boost/lexical_cast.hpp>
#include "ibean.h"

namespace DataKinesis {

	template<class T>
	class BeanBase : public IBean {
		
	protected:
		std::string name;
		Parameters values;
		Refs refs;
		virtual Refs &getRefs() { return refs; }
		std::unique_ptr<T> t;

		void add(T *t) {
			this->t = std::unique_ptr<T>(t);
		}
		bool isConstructed() { return t.get() != 0; }
	public:
		BeanBase(std::string name,const Parameters &values,const Parameters &refs) :name(name),values(values) {
			for (Parameters::value_type val : refs) 
				this->refs[val.first] = Ref(val.second);
		}
		std::string getName() const { return name; }
		template<class U>
		U getValue(const std::string  &name) const {
			Parameters::const_iterator it = values.find(name);
			if (it == values.end())
				throw std::runtime_error("Value not found for " + name);
			return boost::lexical_cast<U>(it->second);
		}
		void *get() {
			if (!t.get())
				throw std::runtime_error("Bean not constructed");
			return t.get();
		}
	};
	template <class T>
	class Bean : public BeanBase<T> {
	public:
	};

	
}
