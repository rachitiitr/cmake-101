#include <iostream>
#include "utils/math.h"
#include <nlohmann/json.hpp>

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
	return 0;
}
