#include "textDisplay.h"
#include "sstream"
#include "iostream"
#include "string"
using namespace std;

void TextDisplay::print (ostream &out, string str1, string str2) {
	istringstream ss1 {str1};
	istringstream ss2 {str2};

	string board1;
	string board2;

	while ((ss1>>board1) && (ss2>>board2)) {
		out << board1;
		out << board2;
		out << endl;
	}
}