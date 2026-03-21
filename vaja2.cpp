#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

namespace ansi_codes {
	constexpr const char* color_reset = "\033[0m";
	constexpr const char* color_red = "\033[31m";
	constexpr const char* color_green = "\033[32m";
	constexpr const char* color_yellow = "\033[33m";
	constexpr const char* color_blue = "\033[34m";

	constexpr const char* console_clear_line = "\33[2K";
}

int main(int argc, char** argv) 
{
	if (argc != 2) {
		cerr << ansi_codes::color_red <<"Invalid program input.\n" << ansi_codes::color_green <<"Valid format: vaja2 <input_file> \n" << ansi_codes::color_reset;  
        return 1; 
	}

	string file_name = argv[1];

	return 0;
}
