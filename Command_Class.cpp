//
//  command class.cpp
//  input output
//
//  Created by Matthew Michnal on 3/28/14.
//  Copyright (c) 2014 Matthew Michnal. All rights reserved.
//

#include "command class.h"
#include "input_output.h"

/* -----------------------------------------------------------------------------
 FUNCTION:         Command_class::Command_class(File_class& div)
 DESCRIPTION:	   Constructor
 NOTES:            Uses the File_class friendship to access data from class
 ----------------------------------------------------------------------------- */
Command_class::Command_class(File_class& div) //This is the constructor
{
	num_translate = NULL;
	firstInt = NULL;
	secondInt = NULL;
	firstDouble = NULL;
	secondDouble = NULL;
	math_operator = NULL;
	array_control = "";
	num_rows = 0;
	hash_tag = '#';
	addition = '+';
	subtraction = '-';
    multiplication = '*';
    division = '/';
    newline = '\n';
    decimal = '.';
    File_size = div.num_bytes;
    num_translate = new char[File_size];

}
/* -----------------------------------------------------------------------------
 FUNCTION:          void Command_class::get_numRows(File_class& div)
 DESCRIPTION:		This function gets the number of rows and dynamically allocates the appropriate c-string array
 NOTES:              Uses the File_class friendship to access data from class
 ----------------------------------------------------------------------------- */
void Command_class::get_numRows(File_class& div)
{
	 if(!div.input_file)
    {
        cout << "this test failed in the command class at method 1 in the interpret file.\n";
        exit(7);
    }

	div.input_file.seekg(0,div.input_file.beg);

	for (int i = 0; i < File_size;i++)
    {
		div.input_file.read(&num_translate[i], File_size);
		if (num_translate[i] == newline)
		{	
			num_rows++;
		}
	}
	
	firstInt = new int[num_rows];
	secondInt = new int[num_rows];
	firstDouble = new double[num_rows];
	secondDouble = new double[num_rows];
	math_operator = new int[num_rows];
}

/* -----------------------------------------------------------------------------
 FUNCTION:        void Command_class::interpret_file(File_class& div1)
 DESCRIPTION:	  This function interprets the input file in the form of 
 NOTES:           Uses the File_class friendship to access data from class
 ----------------------------------------------------------------------------- */
void Command_class::interpret_file(File_class& div1)
{
	
	// tells the input file to go to the beginning so that the information can be interpreted correctly
	div1.input_file.seekg(0,div1.input_file.beg);
	
	

	// This is the for loop that goes through the entire program and reads each byte into the character string for interpretation
	// It uses the file size as a control for how many times the loop occurs. Inside it is where the evaluation statements are found.
	int n = 0;
	
	for (int i = 0; i < File_size;i++)
	{
		
		// Reads in the input statement starting at 0 and incrementing every time a i++ is counted
		div1.input_file.read(&num_translate[i], File_size);

		// Test that looks to see if cstring is a punctation charcter element. If it is then the 
	if(isalpha(num_translate[i]))    
    {
         
    }
        
    if(isspace(num_translate[i]))
    {
			if(num_translate[i] == newline)
			{
				firstInt[n] = 0000;
				secondInt[n] = 0000;
				firstDouble[n] = 0000;
				secondDouble[n] = 0000;
				math_operator[n] = 0000;	
				n++;
			}
    }
       
    if(ispunct(num_translate[i]))    
    {
		 // Here is where we test the hashtag punctuation in order to eliminate comment sections from input. 
		 // a variable type is declared and is not used until the program has determined that the hash tag 
		 // symbol is indeed being used.
          int compare_2 = 0;

            if (num_translate[i] == hash_tag)
            {
				// Here we allocate all of the data arrays to four 0's. in the math class, if all four data structures have the number 0000, then 
				// the program will send a cstring statement indicating the line was a comment from the input file
				// It also moves all of the data arrays on to the next row in order to continue interpretation.
				firstInt[n] = 0000;
				secondInt[n] = 0000;
				firstDouble[n] = 0000;
				secondDouble[n] = 0000;
				math_operator[n] = 0000;
                n++;
				do
                {
                    i++;
                    div1.input_file.read(&num_translate[i], File_size);
                    if (num_translate[i] == newline)
                    {
                        compare_2 = 1;
                    }    
				}while (compare_2 != 1); // This is the end of the do while loop for hash tag comment sections.
			
			//As soon as the cstring is interpreted as new line then the loop is broken and the program continues to move along
	
			}


	}// end of the comment find punctuation conditional statement
		

	if(isdigit(num_translate[i]))
	{
		int firstNum_secondNum = 1;
		int intData_doubleData = 1;
		array_control = "";

		do // beginning of do while loop for math equation. Wont end until newline is recognized. 
        {
		
		convert = num_translate[i];

		if (isdigit(convert))
		{
			if(intData_doubleData == 1)
			{
				if(firstNum_secondNum == 1)
				{
					array_control += convert;
					firstInt[n] = atoi(array_control.c_str());
					firstDouble[n] = 0;
				}
				
				if(firstNum_secondNum == 2)
				{
					array_control += convert;
					secondInt[n] = atoi(array_control.c_str());
					secondDouble[n] = 0;
				}
			}
			else if(intData_doubleData == 2)
			{
				if(firstNum_secondNum == 1)
				{
					array_control += convert;
					firstDouble[n] = atof(array_control.c_str());
					firstInt[n] = 0;
				}
				
				if(firstNum_secondNum == 2)
				{
					array_control += convert;
					secondDouble[n] = atof(array_control.c_str());
					secondInt[n] = 0;
				}
			}
		}
		else if(convert == decimal)
		{
			array_control += convert;
			intData_doubleData = 2;
		}
		else if(convert == addition)
		{
			math_operator[n] = 1;
			firstNum_secondNum = 2;
			array_control = "";
		}
		else if(convert == subtraction)
		{
			math_operator[n] = 2;
			firstNum_secondNum = 2;
			array_control = "";
		}
		else if(convert == multiplication)
		{
			math_operator[n] = 3;
			firstNum_secondNum = 2;
			array_control = "";
		}
		else if(convert == division)
		{
			math_operator[n] = 4;
			firstNum_secondNum = 2;
			array_control = "";
		}
	

		i++;
		div1.input_file.read(&num_translate[i], File_size);
		
		
		}while (num_translate[i] != newline);

		n++; //Signifies the end of a row of mathematical data being processed. This controller moves the array on to the next row.
 
	} // End of the digit conditional tester

	} //End of the for loop.
}
/* -----------------------------------------------------------------------------
 FUNCTION:          int Command_class::return_rows()
 DESCRIPTION:		This function returns the number of rows which is a private data member.
 NOTES:             Put other information here ...
 ----------------------------------------------------------------------------- */
int Command_class::return_rows()
{
	return num_rows;
}
/* -----------------------------------------------------------------------------
 FUNCTION:          Command_class::~Command_class()
 DESCRIPTION:	    Destructor
 NOTES:             Put other information here ...
 ----------------------------------------------------------------------------- */
Command_class::~Command_class() //This is the destructor
{
    delete [] firstInt;
	delete [] secondInt;
	delete [] firstDouble;
	delete [] secondDouble;
	delete [] math_operator;
	delete [] num_translate;
	num_rows = 0;
}
