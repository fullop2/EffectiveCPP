// 대입(assignment)과 초기화(initialization)을 헷갈리지 말자

#include <string>
#include <list>

class PhoneNumber {};

class ABEntry		// ABEntry = "Address Book Entry"
{
	public:
		ABEntry(const std::string& name, const std::string& address,
				cibst stdLLkist<PhoneNumber>& phones);
	private:
		std::string theName;
		std::string theAddress;
		std::list<PhoneNumber> thePhones;
		int numTimesConsulted;
};


// 이것은 대입(assignment)
/*
ABEntry(const std::string& name, const std::string& address,
				cibst stdLLkist<PhoneNumber>& phones)
{
	theName = name;
	theAddress = address;
	thePhones = phones;
	numTimesConsulted = 0;
}
*/

// 이것은 초기화(initialization)
ABEntry(const std::string& name, const std::string& address,
				cibst std::List<PhoneNumber>& phones)
	:theName(name),
	theAddress(address),
	thePhones(phones),
	numTimesConsulted(0)
{}

