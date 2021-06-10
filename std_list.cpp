#include <iostream>
#include <string>
#include <list>

struct borg {
    int id;
    std::string designation;

    //explicit borg(int a, std::string b) { id = a; designation = b; }
};

int std_list_main(int argc, wchar_t* argv[]) {
    std::cout << std::endl << "std_list.cpp" << std::endl;

    std::list<struct borg> collective = {
        {1, "1 of 2"},
        {2, "2 of 2"},
    };

    // TEST: does modifying front() modify the reference in the container?
    struct borg abc = collective.front();
    abc.designation = "OMG";

    for (auto item : collective) {
        std::cout << "id=" << item.id << "; designation=" << item.designation << std::endl;
    }

    return 0;
}
