#include <iostream>
#include <functional>

void demo(int a, int b) {
	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
}

using namespace std::placeholders;

int std_bind_main(int argc, wchar_t* argv[]) {
	std::cout << std::endl << "std_bind.cpp" << std::endl;
	demo(1, 2);

	auto demo2 = std::bind(demo, 2, std::placeholders::_1);
	demo2(3);

	auto demo3 = std::bind(demo, _1, _2);
	demo3(3, 4);

	auto demo4 = std::bind(demo, 4, 5);
	demo4();

	return 0;
}
