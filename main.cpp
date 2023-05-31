// C++ demo application
//
// These are just small programs I write to test language features in C++
// 
// By Brian Clifton (brian@clifton.me)
//

extern int unique_ptr_main(int argc, wchar_t* argv[]);
extern int std_list_main(int argc, wchar_t* argv[]);
extern int functional_main(int argc, wchar_t* argv[]);
extern int tuple_main(int argc, wchar_t* argv[]);
extern int numeric_main(int argc, wchar_t* argv[]);
extern int inheritance_main(int argc, wchar_t* argv[]);
extern int constructor_main(int argc, wchar_t* argv[]);
extern void InstructionSet_main();
extern int decltype_main(int argc, wchar_t* argv[]);

#include <vector>
#include <iostream>
#include <string>

int wmain(int argc, wchar_t* argv[]) {
	unique_ptr_main(argc, argv);
	std_list_main(argc, argv);
	functional_main(argc, argv);
	tuple_main(argc, argv);
	numeric_main(argc, argv);
	inheritance_main(argc, argv);
	constructor_main(argc, argv);
	InstructionSet_main();
	decltype_main(argc, argv);

	return 0;
}
