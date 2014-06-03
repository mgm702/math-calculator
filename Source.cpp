//
//  main.cpp
//  input output
//
//  Created by Matthew Michnal on 3/27/14.
//  Copyright (c) 2014 Matthew Michnal. All rights reserved.
//
#include "command class.h"
#include "input_output.h"
#include "Math_Operator.h"
#include <iostream>
void display_help();
using namespace std;
void cmd_line_error();
int main(int argc,char * argv[])
{
    int compare = strcmp(argv[0], "mycalc");
    if(compare == 0)
    {
        int compare_1 = strcmp(argv[1], "/?");
        
            if(compare_1 == 0)
            {
                cout << "You have enter the help function of the math calculator...\n";
                display_help();
            }
        
        //char* dynamic;
    
        File_class File_open;
        File_open.Open_I_file(argv);
        cout << "The process has begun please wait.... " << endl;
		// Calls to the command class to open up and initialize with File open
		Command_class Command_class(File_open);
		cout << "25%...." << endl;
		//Gets the number of rows in the data file
		Command_class.get_numRows(File_open);
		//Interpret call from the command class
		Command_class.interpret_file(File_open);
		cout << "50%...." << endl;
		Math_Operator math_func;
		math_func.set_size(Command_class);
		math_func.perform_math(Command_class);
		cout << "75%....." << endl;
		File_open.Open_O_file(argv);
		math_func.send_output(File_open);
		cout <<"processing complete, thank you!!\n";


		exit(0);
	}
    else
        cmd_line_error();
    
    return 0;
}
/* -----------------------------------------------------------------------------
 FUNCTION:          void display_help()
 DESCRIPTION:	   This function if prompted displays help for the user on how to use this program. It then exits after completion.
 NOTES:             Put other information here ...
 ----------------------------------------------------------------------------- */
void display_help()
{
    cout << endl;
    cout << "*****WELCOME TO THE MATHCALC PROGRAM*****\n";
    cout << "_________________________________________\n";
	cout << "**This program has a strict syntax that**\n";
	cout << "**must be followed in order to perform **\n";
	cout << "**the appropriate calculations designed**\n";
	cout << "_________________________________________\n";
	cout << "**BELOW IS HOW TO USE THE PROGRAM ENJOY**\n";
	cout << "_________________________________________\n";
    cout << "** mathcalc - Allows user to enter the **\n";
    cout << "** the program and begin interaction   **\n";
    cout << "_________________________________________\n";
    cout << "** mathcalc /? - Take user to this help**\n";
    cout << "** screen and displays help info       **\n";
    cout << "_________________________________________\n";
    cout << "** mathcalc input.txt output.txt -     **\n";
    cout << "** This                                **\n";
    cout << "** syntax will take the input file in  **\n";
    cout << "** command line and begin to take data **\n";
    cout << "** from file. The program will then    **\n";
    cout << "** perform the appropriate calc based  **\n";
    cout << "** on the files information..........  **\n";
    cout << "** The file will then send the results **\n";
    cout << "** of each calculation to the desired  **\n";
    cout << "** output file indicated in the cmdline**\n";
    cout << "_________________________________________\n";
    cout << "**************ENJOY!!!*******************\n";
    
    
	exit(1);
}
/* -----------------------------------------------------------------------------
 FUNCTION:          void cmd_line_error()
 DESCRIPTION:	   This function is called if the user doesn't follow the correct protocol when trying to
 access information from the program.
 NOTES:             Put other information here ...
 ----------------------------------------------------------------------------- */
void cmd_line_error()
{
    cout << "Not enough command line arguments..." << endl;
    //display_help ();
    exit(0);
}



