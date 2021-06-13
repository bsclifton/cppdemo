#include <iostream>
#include <tuple>

int tuple_main(int argc, wchar_t* argv[]) {
    std::cout << std::endl << __FILE__ << std::endl;

    auto test = std::make_tuple(5, 4, 3);

    int i, j, k;
    std::tie(i, j, k) = test;

    std::cout << "i=" << i << "; j=" << j << "; k=" << k << std::endl;

    return 0;
}
