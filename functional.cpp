#include <iostream>
#include <functional>

void demo(int a, int b) {
	std::cout << "demo] " << a << " + " << b << " = " << (a + b) << std::endl;
}

void demo_ref(int& a, int& b) {
	a++;
	b++;
}

class ExampleObject {
public:
	int id;
	ExampleObject(int object_id) {
		id = object_id;
	}
	virtual void print() {
		std::cout << "[ExampleObject id=" << id << "]" << std::endl;
	}
	int method_with_arg(int a) {
		return id + a;
	}
};

class ExampleDerivedObject : public ExampleObject {
public:
	ExampleDerivedObject(int object_id) : ExampleObject(object_id) {}
	void print() {
		std::cout << "[ExampleDerivedObject id=" << id << "]" << std::endl;
	}
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
	// you can get a reference to a method without the instance
	ExampleObject a(1);
	ExampleDerivedObject b(2);

	auto example = std::mem_fn(&ExampleObject::print);
	// it works kind of similar (IMO) to apply in JavaScript
	example(a);
	// mem_fn is smart enough to work out derived types
	example(b);

	// you can call with args and also capture return values
	auto example2 = std::mem_fn(&ExampleObject::method_with_arg);
	std::cout << "example2 with instance `a` and arg `5` returned " << example2(a, 5) << std::endl;

	return 0;
}
