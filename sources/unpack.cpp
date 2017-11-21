#include <json/json.h>
#include <valijson/adapters/jsoncpp_adapter.hpp>
#include <valijson/utils/jsoncpp_utils.hpp>
#include <iostream>
#include <fstream>
#include <iomanip> // for std::setw

using json = nlohmann::json;

int main(int argc, char const *argv[]) {
	try {
		if(argc == 1)
			throw std::runtime_error("ERROR: have no any path...");
		
		// read a JSON file
		std::ifstream in( argv[1] );
		json _j;
		in >> _j;
		in.close();

		std::cout << std::setw(4) << _j << std::endl;

	} catch(const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

	return 0;
}
