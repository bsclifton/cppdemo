// C++ demo application
//
// These are just small programs I write to test language features in C++
// 
// By Brian Clifton (brian@clifton.me)
//

extern int unique_ptr_main(int argc, wchar_t* argv[]);
extern int std_list_main(int argc, wchar_t* argv[]);
extern int std_bind_main(int argc, wchar_t* argv[]);
// ..

int wmain(int argc, wchar_t* argv[]) {
	unique_ptr_main(argc, argv);
	std_list_main(argc, argv);
	std_bind_main(argc, argv);
	// ..

	return 0;
}
