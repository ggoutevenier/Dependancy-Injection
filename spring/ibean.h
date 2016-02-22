#pragma once
#include <string>
#include <map>
#include <stdexcept>

namespace DataKinesis {
	class ApplicationContext;
	class IBean {
		friend class ApplicationContext;
	public:
		virtual std::string getName() const = 0;
		virtual ~IBean() {}
		typedef std::map<std::string, std::string> Parameters;
		struct Ref {
			std::string name;
			IBean *bean;
			Ref() :name(""), bean(0) {}
			Ref(const std::string &name) :name(name), bean(0) {}
			Ref(const Ref &ref) :name(ref.name), bean(ref.bean) {}
		};
		virtual void *get() = 0;
		typedef std::map<std::string, Ref> Refs;
	protected:
		virtual Refs &getRefs() = 0;
		template<class T>
		T &getRef(std::string name) {
			Refs::iterator it = getRefs().find(name);
			if (it == getRefs().end())
				throw std::runtime_error("unable to find ref " + name);
			return *(T*)it->second.bean->get();
		}
		virtual void construct() = 0;
	};
}
