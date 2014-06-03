//
//  input_output.cpp
//  input output
//
//  Created by Matthew Michnal on 3/27/14.
//  Copyright (c) 2014 Matthew Michnal. All rights reserved.
//

#include <stdio.h>
#include "input_output.h"

using namespace std;
/* -----------------------------------------------------------------------------
 FUNCTION:          void File_class::Open_I_file(char** argv)
 DESCRIPTION:	   This function opens the input file for data interpretation. It takes the character input from cmd prompt
 NOTES:             Put other information here ...
 ----------------------------------------------------------------------------- */
void File_class::Open_I_file(char** argv)
{
    
    input_file.open(argv[1], ios::in|ios::binary);
    if(!input_file)
    {
        cout << "This file could not open.\n";
        cout << "The program will now terminate.\n";
        exit(2);
    }

    
    input_file.seekg(0L, ios::end);
    num_bytes = input_file.tellg();

}
/* -----------------------------------------------------------------------------
 FUNCTION:         void File_class::Open_O_file(char** argv)
 DESCRIPTION:	  This function opens the output file using the cmd instructions from cmd prompt 
 NOTES:             Put other information here ...
 ----------------------------------------------------------------------------- */
void File_class::Open_O_file(char** argv)
{
    output_file.open(argv[2], ios::out|ios::binary);
    if(!output_file)
    {
        cout << "This file could not open.\n";
        cout << "The program will now terminate.\n";
        exit(3);
    }
}
/* -----------------------------------------------------------------------------
 FUNCTION:         long File_class::return_Bytes()
 DESCRIPTION:	   Returns the number of bytes in the input file. 
 NOTES:             Put other information here ...
 ----------------------------------------------------------------------------- */
long File_class::return_Bytes()
{
    return num_bytes;
}
/* -----------------------------------------------------------------------------
 FUNCTION:          File_class::~File_class()
 DESCRIPTION:	    Destructor
 NOTES:             Put other information here ...
 ----------------------------------------------------------------------------- */
File_class::~File_class()
{

}