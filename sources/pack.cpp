#include <json/json.h>
#include <fstream>
#include <iomanip> // for std::setw

using json = nlohmann::json;

struct Email {
  std::string nickname;
  std::string server;
};

struct Person {
  std::string  first_name;
  std::string  last_name;
  Email        email;
  size_t       age;
  std::string  phone;
  void devideEmail();
};


int main(int argc, char const *argv[]) {
	try {
		if(argc == 1)
			throw std::runtime_error("ERROR: have no any path...");

		//  Create struct & fill it
		Person A;

		cout << "Enter data to fields of the Person structure." << endl;
		cout << "First name:" << endl;
		cin >> A.first_name;
		cout << "Last name:" << endl;
		cin >> A.last_name;
		cout << "Email:" << endl;
		A.devideEmail();
		cout << "Age(optional):" << endl;
		cin >> A.age;
		cout << "Phone(optional):" << endl;
		cin >> A.phone;


		// json j;
		// j["Fisrt name"] = A.first_name;

		json j = { "[person]", {
			  { "Fisrt name",	A.first_name },
			  { "Last name",	A.last_name },
			  { "Email",		A.email.nickname + A.email.server },
			  { "Age",			A.age },
			  { "Phone",		A.phone }
			}
		};

		// write prettified JSON to another file
		std::ofstream out( argv[1] );
		out << std::setw(4) << j << std::endl;
		out.close();

	} catch(const std::exception& e) {
        cout << e.what() << endl;
    }

	return 0;
}

void Person::devideEmail() {
  	std::string address;
  	cin >> address;
  	std::string::size_type pos = address.find("@");
	if(pos != std::string::npos) {
		email.nickname = address.substr(0, pos);
		email.server = address.substr(pos);
	} else {
		throw std::runtime_error("ERROR: incorret email address...");
	}
};
