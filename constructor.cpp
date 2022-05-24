// implicit copy constructor demo
// this is why it's good to explicitly delete the copy constructor and operator=
// unless you intend to use that behavior

#include <iostream>
enum class Environment { kDevelopment, kStaging, kProduction };

void print_env(Environment e) {
	switch (e) {
	case Environment::kDevelopment:
		std::cout << "dev";
		break;
	case Environment::kStaging:
		std::cout << "staging";
		break;
	case Environment::kProduction:
		std::cout << "prod";
		break;
	}
}

struct SampleParam {
	// NOTE: default environment when this runs
	Environment environment = Environment::kProduction;

	SampleParam() {
		std::cout << "SampleParam(";
		print_env(environment);
		std::cout << ")" << std::endl;
	}
	SampleParam(const SampleParam& copy) {
		environment = copy.environment;
		std::cout << "SampleParam_COPY(";
		print_env(environment);
		std::cout << ")" << std::endl;
	}
	~SampleParam() {
		std::cout << "~SampleParam" << std::endl;
	}
};

SampleParam GetParam(Environment e) {
	SampleParam o;
	o.environment = e;
	return o;
}

class SampleObject {
public:
	SampleParam _options;
	SampleObject(Environment e) : _options(GetParam(e)) {
		std::cout << "SampleObject()" << std::endl;
	}
	virtual ~SampleObject() {
		std::cout << "~SampleObject()" << std::endl;
	}
};

int constructor_main(int argc, wchar_t* argv[]) {
	std::cout << std::endl << __FILE__ << std::endl;

	SampleObject abc(Environment::kDevelopment);
	std::cout << "printing instance param value: ";
	print_env(abc._options.environment);
	std::cout << std::endl;

	return 0;
}