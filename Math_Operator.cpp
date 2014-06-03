#include "Math_Operator.h"
#include "Command class.h"
#include "input_output.h"

/* -----------------------------------------------------------------------------
 FUNCTION:          Math_Operator::Math_Operator()
 DESCRIPTION:	    Constructor
 NOTES:             Put other information here ...
 ----------------------------------------------------------------------------- */
Math_Operator::Math_Operator()
{
	sum_int = 0;
	sum_double = 0;
	column_size = 0;
}
/* -----------------------------------------------------------------------------
 FUNCTION:          void Math_Operator::set_size(Command_class& div)
 DESCRIPTION:	    This sets the size of the output string based on the information from Command Class
 NOTES:             Information is pased in through Friendship Class
 ----------------------------------------------------------------------------- */
void Math_Operator::set_size(Command_class& div)
{
	column_size = div.return_rows();
	final_outFile = new string[column_size];
}
/* -----------------------------------------------------------------------------
 FUNCTION:          void Math_Operator::perform_math(Command_class& div)
 DESCRIPTION:	    This function performs the actual mathematics. It then stores its results and the variables used in a string array
 NOTES:             The whole purpose of this program is found in this function. 
 ----------------------------------------------------------------------------- */
void Math_Operator::perform_math(Command_class& div)
{
	for(int i=0; i < column_size;)
	{
		//This statement is for the comments area or nonrelevant information. Also 0 + 0 is stored in this area as well
		if(div.firstDouble[i] == 0 && div.secondDouble[i] == 0 && div.firstInt[i] == 0 && div.secondInt[i] == 0)
		{
			
			final_outFile[i] = "No math operations were found. This row was either a comment or non mathematic function.\r\n";
		
		}
		//Statement indicating that the ints are both zero and thus the number must be a double data type
		else if(div.firstInt[i] == 0 && div.secondInt[i] == 0)
		{
			//Switch statement during each for loop is interpreted and passed to correct "operation" case
			switch(div.math_operator[i])
			{
				case 1:
					sum_double = div.firstDouble[i] + div.secondDouble[i];
					output_stringstream << "The sum of ";
					output_stringstream << div.firstDouble[i];
					output_stringstream << " + ";
					output_stringstream << div.secondDouble[i];
					output_stringstream << " = ";
					output_stringstream << sum_double;
					final_outFile[i] = output_stringstream.str() + "\r\n";
					output_stringstream.str("");
					output_stringstream.clear();
					break;
				case 2:
					sum_double = div.firstDouble[i] - div.secondDouble[i];
					output_stringstream << "The sum of ";
					output_stringstream << div.firstDouble[i];
					output_stringstream << " - ";
					output_stringstream << div.secondDouble[i];
					output_stringstream << " = ";
					output_stringstream << sum_double;
					output_stringstream << endl;
					final_outFile[i] = output_stringstream.str() + "\r\n";
					output_stringstream.str("");
					output_stringstream.clear();
					break;
				case 3:
					sum_double = div.firstDouble[i] * div.secondDouble[i];
						output_stringstream  << "The sum of ";
						output_stringstream  << div.firstDouble[i];
						output_stringstream  << " * ";
						output_stringstream  << div.secondDouble[i];
						output_stringstream  << " = ";
						output_stringstream  << sum_double;
					final_outFile[i] = output_stringstream.str() + "\r\n";
					output_stringstream.str("");
					output_stringstream.clear();
					break;
				case 4:
					sum_double = div.firstDouble[i] / div.secondDouble[i];
						output_stringstream  << "The sum of ";
						output_stringstream  << div.firstDouble[i];
						output_stringstream  << " / ";
						output_stringstream  << div.secondDouble[i];
						output_stringstream  << " = ";
						output_stringstream  << sum_double;
					final_outFile[i] = output_stringstream.str() + "\r\n";
					output_stringstream.str("");
					output_stringstream.clear();
					break;
			}

		}
		//Statement indicating that the doubles are both zero and thus the number must be a int data type
		else if(div.firstDouble[i] == 0 && div.secondDouble[i] == 0)
		{
			switch(div.math_operator[i])
			{				
				case 1:
					sum_int = div.firstInt[i] + div.secondInt[i];
					output_stringstream << "The sum of ";
					output_stringstream << div.firstInt[i];
					output_stringstream << " + ";
					output_stringstream << div.secondInt[i];
					output_stringstream << " = ";
					output_stringstream << sum_int;
					final_outFile[i] = output_stringstream.str() + "\r\n";
					output_stringstream.str("");
					output_stringstream.clear();
					break;
				case 2:
					sum_int = div.firstInt[i] - div.secondInt[i];
					output_stringstream << "The sum of ";
					output_stringstream << div.firstInt[i];
					output_stringstream << " - ";
					output_stringstream << div.secondInt[i];
					output_stringstream << " = ";
					output_stringstream << sum_int;
					final_outFile[i] = output_stringstream.str() + "\r\n";
					output_stringstream.str("");
					output_stringstream.clear();
					break;
				case 3:
					sum_int = div.firstInt[i] * div.secondInt[i];
					output_stringstream << "The sum of ";
					output_stringstream << div.firstInt[i];
					output_stringstream << " * ";
					output_stringstream << div.secondInt[i];
					output_stringstream << " = ";
					output_stringstream << sum_int;
					final_outFile[i] = output_stringstream.str() + "\r\n";
					output_stringstream.str("");
					output_stringstream.clear();
					break;
				case 4:
					sum_int = div.firstInt[i] / div.secondInt[i];
					output_stringstream << "The sum of ";
					output_stringstream << div.firstInt[i];
					output_stringstream << " / ";
					output_stringstream << div.secondInt[i];
					output_stringstream << " = ";
					output_stringstream << sum_int;
					final_outFile[i] = output_stringstream.str() + "\r\n";
					output_stringstream.str("");
					output_stringstream.clear();
					break;
			}
		
		}
		sum_int = 0;
		sum_double = 0;
		i++;
	}

}
/* -----------------------------------------------------------------------------
 FUNCTION:          void Math_Operator::send_output(File_class& div)
 DESCRIPTION:	    This function sends the output to file designated by the user in the cmd prompt
 NOTES:             Information is pased in through Friendship Class
 ----------------------------------------------------------------------------- */
void Math_Operator::send_output(File_class& div)
{
	 if(!div.output_file)
    {
		cout << "this test failed in the command class at method 1 in the interpret file.\n";
        exit(8);
	}

	div.output_file.seekp(0L, ios::beg);

	
	 for(int i = 0; i < column_size; i++)
	 {
		 div.output_file << final_outFile[i];
	 }
	
}
/* -----------------------------------------------------------------------------
 FUNCTION:          void File_class::Open_I_file(char** argv)
 DESCRIPTION:	   This function opens the input file for data interpretation. It takes the character input from cmd prompt
 NOTES:             Put other information here ...
 ----------------------------------------------------------------------------- */
Math_Operator::~Math_Operator()
{
	delete [] final_outFile;
}