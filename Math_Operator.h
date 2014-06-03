
#ifndef MATH_OPERATOR_H
#define MATH_OPERATOR_H
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <cstring>
#include <sstream> 
using namespace std;

class Command_class;
class File_class;

class Math_Operator
{
private:
	int sum_int;
	double sum_double;
	int column_size;
public:
	stringstream output_stringstream;
	string* final_outFile;
	Math_Operator();
	void set_size(Command_class&);
	void perform_math(Command_class&);
	void send_output(File_class&);
	
	~Math_Operator();
};
#endif