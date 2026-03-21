#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


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

    vector<unsigned char> res; 
    if (!input_stream) {
        error("Coudln't open target for reading. ");
    }

    string line;
    while (getline(input_stream, line)) {
        for (const char c : line) {
            res.push_back(static_cast<unsigned char>(c));
        }
    }

    input_stream.close(); 

    return res; 
}

int main(int argc, char** argv) 
{
    ios_base::sync_with_stdio(false); // for better iostreams performance

	if (argc != 2) {
		cerr << ansi_codes::color_red <<"Invalid program input.\n" << ansi_codes::color_green <<"Valid format: vaja2 <input_file> \n" << ansi_codes::color_reset;  
        return 1; 
	}

	string file_name = argv[1];
    const vector<unsigned char> input_vec = read(file_name); 

    


	return 0;
}
