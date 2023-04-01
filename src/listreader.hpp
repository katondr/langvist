#ifndef LISTREADER
#define LISTREADER

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
//#include "booklist.hpp"

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::ostringstream;
using std::istringstream;

string readFileIntoString(const string& path) {
	auto ss = ostringstream{};
	ifstream input_file(path);
	if (!input_file.is_open()){
		cerr << "Could not open the file - '"
			<< path << "'" << endl;
		exit(EXIT_FAILURE);
	}
	ss << input_file.rdbuf();
	return ss.str();
}

extern std::map<int, std::vector<string>> books;

int listreader()
{
	string filename("books/books.csv");
	string file_contents;
	//std::map<int, std::vector<string>> csv_contents;
	//std::map<int, std::vector<string>> books;
	char delimiter = ',';

	file_contents = readFileIntoString(filename);

	istringstream sstream(file_contents);
	std::vector<string> items;
	string record;

	int counter = 0;
	while (std::getline(sstream, record)) {
		istringstream line(record);
		while (std::getline(line, record, delimiter)) {
			//cout << record << "\n";
			items.push_back(record);
		}

	  	books[counter] = items;
		items.clear();
		counter += 1;
	}

	return 0;
}

void displaymenu()
{
	//listreader();
	std::cout << "\n";
	//std::cout << books.size();
	std::cout << "2. Max Havelaar\n";
}
#endif
