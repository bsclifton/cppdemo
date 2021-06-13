#include <iostream>
#include <string>
#include <list>

struct borg {
    int id;
    std::string designation;

    borg() = delete;
    borg(const borg& copy) {
        this->id = copy.id;
        this->designation = copy.designation;
        std::cout << "copied\n";
    }
    borg(int a, std::string b) { id = a; designation = b; std::cout << "created\n"; }
    ~borg() { std::cout << "~destroyed\n"; }
};

int std_list_main(int argc, wchar_t* argv[]) {
    std::cout << std::endl << __FILE__ << std::endl;

    std::list<struct borg> collective = {
        borg(1, "1 of 2"),
        borg(2, "2 of 2"),
    };

    // front() does return a reference which can be modified
    struct borg& abc = collective.front();
    abc.designation = "OMG";

    // ignored when reference not set
    struct borg def = collective.front();
    def.id = 5;

    for (auto& item : collective) {
        std::cout << "id=" << item.id << "; designation=" << item.designation << std::endl;
    }

    return 0;
}
