//
//  input_output.h
//  input output
//
//  Created by Matthew Michnal on 3/27/14.
//  Copyright (c) 2014 Matthew Michnal. All rights reserved.
//

#ifndef input_output_input_output_h
#define input_output_input_output_h
#include <fstream>
#include <iostream>
#include "command class.h"
#include "Math_Operator.h"
using namespace std;

class File_class
{
private:
    ifstream input_file;
    ofstream output_file;
    long num_bytes;
public:
    //opens the input file
    void Open_I_file(char**);
    //opens the output file
	void Open_O_file(char**);
    //used to return the number of bytes which is a private data member
	long return_Bytes();
    
	//Friends for the command class function. Calls to the File class function for information from input file
    friend Command_class::Command_class(File_class&);
    friend void Command_class::get_numRows(File_class&);
	friend void Command_class::interpret_file(File_class&);
	
	//Friend function that calls to the File class for the output folder information so that it can send data
	friend void Math_Operator::send_output(File_class&);
	~File_class();
};

#endif
