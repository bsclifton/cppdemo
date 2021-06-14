#include <iostream>
#include <numeric>
#include <vector>

struct ExampleType {
	int value;
};

int numeric_main(int argc, wchar_t* argv[]) {

	std::vector<ExampleType> items = {
		{4}, {2}, {10}
	};
	int total;

	// NOTE TO SELF: read more about lambda captures
	total = std::accumulate(items.begin(), items.end(), 0, [&](int a, ExampleType b) { return a + b.value; });
	std::cout << "accumulate 1: " << total << std::endl;

	// alternative to lambda; using range-based for loop
	total = 0;
	for (auto item : items) {
		total += item.value;
	}
	std::cout << "accumulate 2: " << total << std::endl;

	return 0;
}