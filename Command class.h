//
//  command class.h
//  input output
//
//  Created by Matthew Michnal on 3/28/14.
//  Copyright (c) 2014 Matthew Michnal. All rights reserved.
//

#ifndef __input_output__command_class__
#define __input_output__command_class__
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <cstring>
#include "Math_Operator.h"
using namespace std;

class File_class;

class Command_class
{
private:
    // char string that will be used to translate the numbers into their appropriate data type array
	char* num_translate;
	char convert;
	string array_control;
	// Holds the file size which it receives from the input_output class via friend access.
    long File_size;
	// Holds the number of rows in the input file. Needed to dynamically allocate the correct array size for math problems.
	int num_rows;
	// These class member variables are used to hold the positions for the different punctuation
	// That needs to be interpreted. It is set up inside the constructor
    char hash_tag;
    char addition;
    char subtraction;
    char multiplication;
    char division;
    char newline;
    char decimal;
public:
	int* firstInt; 
	int* secondInt;
    // two pointers to double arrays, that will be dynamically allocated when the file size is provided
	double* firstDouble; 
	double*	secondDouble; 
	// Integer array to hold the math operations for each of the problems in the input file. Based on numeric return
	// This array passes its data on to the math class so that it can be interpreted for calculation.
	int* math_operator;
	Command_class();
    Command_class(File_class&);
	void get_numRows(File_class&);
	void interpret_file(File_class&);
	int return_rows();

    //friend Math_Operator::	
	friend void Math_Operator::set_size(Command_class&);
	friend void Math_Operator::perform_math(Command_class&);


    ~Command_class();

};


#endif /* defined(__input_output__command_class__) */
