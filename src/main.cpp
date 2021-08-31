#include <iostream>
#include "utils/math.h"
#include <nlohmann/json.hpp>
#include "SuperMan.pb.h"
using json = nlohmann::json;
int main() {
	std::cout << "hi world ok" << std::endl;
	std::cout << utils::add(3, 4) << std::endl;
	// store a string in a JSON value
	json j2 = {
		{"pi", 3.141},
		{"happy", true},
		{"name", "Niels"},
		{"nothing", nullptr},
		{"answer", {
			{"everything", 42}
		}},
		{"list", {1, 0, 2}},
		{"object", {
			{"currency", "USD"},
			{"value", 42.99}
		}}
	};
	// retrieve the serialized value (explicit JSON serialization)
	std::string serialized_string = j2.dump();

	std::cout << serialized_string << std::endl;

	tutorial::Person person;
	person.set_id(1);
	person.set_name("rachit");
	person.set_email("rachitiitr@outlook.com");
	auto phone = person.add_phones();
	phone->set_number("9999999999");
	phone->set_type(tutorial::Person_PhoneType::Person_PhoneType_MOBILE);

	phone = person.add_phones();
	phone->set_number("8888888888");
	phone->set_type(tutorial::Person_PhoneType::Person_PhoneType_WORK);

	std::cout << person.ShortDebugString() << std::endl;

	auto p2 = person;
	p2.AddExtension(tutorial::powers, tutorial::Power::FLY);
	p2.AddExtension(tutorial::powers, tutorial::Power::HULK);
	std::cout << p2.ShortDebugString() << std::endl;
	return 0;
}

/*
Expected Output:
hi world ok
7
{"answer":{"everything":42},"happy":true,"list":[1,0,2],"name":"Niels","nothing":null,"object":{"currency":"USD","value":42.99},"pi":3.141}
name: "rachit" id: 1 email: "rachitiitr@outlook.com" phones { number: "9999999999" type: MOBILE } phones { number: "8888888888" type: WORK }
name: "rachit" id: 1 email: "rachitiitr@outlook.com" phones { number: "9999999999" type: MOBILE } phones { number: "8888888888" type: WORK } [tutorial.powers]: FLY [tutorial.powers]: HULK
*/