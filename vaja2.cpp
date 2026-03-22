#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <execution>
#include <cstring>

using namespace std;

constexpr const char* output_file_name = "primer_izhoda";

namespace ansi_codes {
	constexpr const char* color_reset = "\033[0m";
	constexpr const char* color_red = "\033[31m";
	constexpr const char* color_green = "\033[32m";
	constexpr const char* color_yellow = "\033[33m";
	constexpr const char* color_blue = "\033[34m";

	constexpr const char* console_clear_line = "\33[2K";
}

void error(const string& msg) {
    throw runtime_error(msg); 
}

vector<unsigned char> read(const string& file_name) {
    ifstream input_stream {file_name}; 
    if (!input_stream) {
        error("Coudln't open target for reading. ");
    }

    
    vector<unsigned char> res; 
    unsigned int num; 
    while (input_stream >> num) {
        if (num > 255) error("Value out of unsigned char range. " + to_string(num) + "\n");
        res.push_back(static_cast<unsigned char>(num));
    }
    
    return res; 
}

void write(const vector<unsigned char>& output_vec) {}

int main(int argc, char** argv) 
{
    ios_base::sync_with_stdio(false); // for better iostreams performance

	if (argc != 2) {
		cerr << ansi_codes::color_red <<"Invalid program input.\n" << ansi_codes::color_green <<"Valid format: vaja2 <input_file> \n" << ansi_codes::color_reset;  
        return 1; 
	}

	string file_name = argv[1];
    const vector<unsigned char> input_vec = read(file_name); 
    write(input_vec);
    


	return 0;
}
