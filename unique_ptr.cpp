#include <iostream>
#include <vector>
#include <memory>

#define BSC_UNIQUE_ALLOW_COPY

struct ExampleType {
    int id;
    std::string name;
    std::string desc;

    explicit ExampleType(int a, std::string b, std::string c) {
        id = a;
        name = b;
        desc = c;
        std::cout << "creating ExampleType [name=" << name << ", addr=" << this << "]" << std::endl;
    }
    ~ExampleType() {
        std::cout << "destroying ExampleType [name=" << name << ", addr=" << this << "]" << std::endl;
    }

    // NOTE: it may be a good idea to prevent accidental copy constructor usage
    #ifdef BSC_UNIQUE_ALLOW_COPY
    ExampleType(ExampleType const& copy) {
        id = copy.id;
        name = copy.name + " (copy)";
        desc = copy.desc;
        std::cout << "copying ExampleType [name=" << name << ", addr=" << this << "]" << std::endl;
    }
    #else
    ExampleType(ExampleType const&) = delete;
    #endif
};

std::vector<std::unique_ptr<ExampleType>> GetList() {
    std::cout << "creating list" << std::endl;

    std::vector<std::unique_ptr<ExampleType>> list;
    
    list.push_back(std::make_unique<ExampleType>( 2, "first", "example item 1" ));
    list.push_back(std::make_unique<ExampleType>( 3, "second", "example item 2" ));
    list.push_back(std::make_unique<ExampleType>( 4, "third", "example item 3" ));

    std::cout << "list created" << std::endl;

    return list;
}

int unique_ptr_main(int argc, wchar_t* argv[]) {
    std::cout << std::endl << __FILE__ << std::endl;

    auto demo = std::make_unique<ExampleType>(1, "function scope", "demo item" );

    // TEST: when does the destroy happen?
    std::vector<std::unique_ptr<ExampleType>> my_list = GetList();
    for (size_t i = 0; i < my_list.size(); i++) {
        std::unique_ptr<ExampleType> temp = std::move(my_list[i]);
        std::cout << "moving ExampleType [name= " << temp->name << ", addr=" << temp << "]" << std::endl;
    }
    std::cout << "all list references should be cleaned up" << std::endl;

    #ifdef BSC_UNIQUE_ALLOW_COPY
    auto demo2 = std::make_unique<ExampleType>(ExampleType{ 5, "init w/ copy", "copy constructor demo" });
    #endif

    std::cout << "end of program" << std::endl;

    return 0;
}
