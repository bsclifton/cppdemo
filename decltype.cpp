#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

struct Bubba {
    int a;
};

struct Smith {
    int b;
};


int decltype_main(int argc, wchar_t* argv[]) {
    std::cout << std::endl << __FILE__ << std::endl;
    int a = 22;
    decltype(a) b = 44;

    std::vector<decltype(a)> c(100, a);

    std::cout << std::boolalpha << std::is_same<Bubba, Smith>::value << std::endl;
    std::cout << std::boolalpha << std::is_same_v<long, int64_t> << std::endl;
    std::cout << std::boolalpha << std::is_same_v<decltype(a), decltype(b)> << std::endl;

    return 0;
}
