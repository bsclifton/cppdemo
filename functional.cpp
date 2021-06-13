#include <iostream>
#include <vector>
#include <functional>
#include <numeric>

void demo(int a, int b) {
	std::cout << "demo] " << a << " + " << b << " = " << (a + b) << std::endl;
}

void demo_ref(int& a, int& b) {
	a++;
	b++;
}

class ExampleType {
public:
	int value;
};


using namespace std::placeholders;

int functional_main(int argc, wchar_t* argv[]) {
	std::cout << std::endl << __FILE__ << std::endl;
	demo(1, 2);

	// A few simple std::bind usages
	auto demo2 = std::bind(demo, 2, std::placeholders::_1);
	demo2(3);

	auto demo3 = std::bind(demo, _1, _2);
	demo3(3, 4);

	auto demo4 = std::bind(demo, 4, 5);
	demo4();

	// NOTE: References are dereferenced before std::bind
	int i = 1, j = 2;
	auto demo5 = std::bind(demo_ref, i, j);
	demo5(); // variables are not changed
	std::cout << "W/O REF ADAPTER]] i=" << i << "; j=" << j << std::endl;

	// std::ref and std::cref can be used
	auto demo6 = std::bind(demo_ref, std::ref(i), std::ref(j));
	demo6(); // variables ARE changed
	std::cout << "W/ REF ADAPTER]] i=" << i << "; j=" << j << std::endl;

	// example usage of bind WITHOUT using auto
	std::function<void(int)> demo_one_param = std::bind(demo, 200, _1);
	demo_one_param(100);

	// Function type can be set to a function matching signature (and called).
	std::function<void(int, int)> demo7 = demo;
	demo7(8, 10);


	// another interesting one; mem_fn
	// 
	// can be demonstrated via several ways to call accumulate
	std::vector<ExampleType> items = {
		{4}, {2}, {10}
	};

	int total;
	
	//bad (mem_fn is deprecated; don't use!)
	//total = std::accumulate(items.begin(), items.end(), 0, std::mem_fn(&ExampleType::value));

	// better
	total = std::accumulate(items.begin(), items.end(), 0, [&](int a, ExampleType b) { return a + b.value; });

	// best
	total = 0;
	for (auto item : items) {
		total += item.value;
	}

	return 0;
}
