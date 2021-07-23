#include <iostream>
#include <string>

class BaseClass {
public:
    std::string name;
    virtual std::string get_details() {
        return name;
    }
    BaseClass(BaseClass const&) = delete;
    /*BaseClass(BaseClass const& obj) {
        name = obj.name;
        std::cout << "copying BaseClass (" << this << ") " << std::endl;
    }*/
    BaseClass() {
        std::cout << "creating BaseClass (" << this << ") " << std::endl;
    }
    virtual ~BaseClass() {
        std::cout << "destroying ~BaseClass(" << this << ") " << std::endl;
    }
};

class DerivedClass : public BaseClass {
public:
    int age;
    std::string get_details() override {
        return name + " / " + std::to_string(age);
    }

    DerivedClass(std::string n, int a) {
        std::cout << "creating DerivedClass (" << this << ") " << std::endl;
        name = n;
        age = a;
    }

    virtual ~DerivedClass() {
        std::cout << "destroying ~DerivedClass(" << this << ") " << std::endl;
    }
};

int inheritance_main(int argc, wchar_t* argv[]) {
    std::cout << std::endl << __FILE__ << std::endl;

    DerivedClass a("Bubba", 50);

    // downcast
    BaseClass* b = &a;

    // upcast
    DerivedClass* c = static_cast<DerivedClass*>(b);

    // static cast not as pointer
    // not allowed because copy constructor deleted
    //BaseClass d = static_cast<BaseClass>(a);

    // resolving virtual function
    std::cout << b->get_details() << std::endl;

    return 0;
}
