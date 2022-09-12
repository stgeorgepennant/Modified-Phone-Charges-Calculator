/*************************************************************************
Name: St George Pennant   Z#: 23401887
Course:
Professor: Dr. Lofton Bullard
Due Date: October 9, 2018   Due Time: 11:59
Total Points: 20
Assignment 6: call_stats4.cpp
Description:
Note: In this assignment you will
1. Read the contents of a datafile one record at a time into an array of records;
2. Process the data stored in an array of records;
3. Print the records stored in an array to a datafile using an ofstream (output file stream) object;
4. Use an array of record records;
6. Use an ifstream object;
7. Use an ofstream object;
**************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int SIZE = 200; // The capacity of the array which is the total amount of memory allocated to the array.  The is a static array, 
					  // therefore the compiler will manage its memory, allocate and de-allocate the memory.

// Sample record (class with no functionality)
class call_record
{
public:
	string cell_number;
	int relays;
	int call_length;
	double net_cost;
	double tax_rate;
	double call_tax;
	double total_cost;
};

// Function prototype -- allows compiler to setup for function calls
void Input(call_record call_DB[], int & count);
void Output(const call_record call_DB[], const int & count);
void Process(call_record call_DB[], const int & count);

//***********************************************************************
// Name: Input
// Precondition:
// Postcondition:
// Description:
//************************************************************************
void Input(call_record call_DB[], int & count)
{
	ifstream in; // Input file stream object declaration
	count = 0;  // Remember to initialize count before the first come
	in.open("call_data.txt"); // Bind the file "call_data.txt" to the input file stream "in".
	if (in.fail()) // If file not found print message and exit program
	{
		cout << "Input file did not open correctly" << endl;
		exit(1);
	}
	// Remember to use a while loop when reading from a file because you do not know how many records you will be reading.
	while (!in.eof())
	{
		in >> call_DB[count].cell_number;
		// You put in statements to read relay and call length
		in >> call_DB[count].relays;
		in >> call_DB[count].call_length;
		count++;
	}
	in.close();
}
//***********************************************************************
// Name: Output
// Precondition:
// Postcondition:
// Description:
//************************************************************************

void Output(const call_record call_DB[], const int & count)
{
	ofstream out; // Declare the output file stream "out".
	out.open("weekly4_call_info.txt"); // Bind the file "weekly4_call_info.txt" to the output file stream "out".
									   // Use the magic formula to format your output. Remember that you are not using "cout".  
									   // In this example we are using "out". eg... out.setf(showpoint);
	if (out.fail()) // If problem opening file, print message and exit program
	{
		cout << "Output file did not open correctly" << endl;
		exit(1);
	}
	// Use a "for" loop here to print the output to file
	for (int i = 0; i < count; i++)
	{
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout.setf(ios::fixed);
		/********************************************/

		cout << call_DB[i].cell_number << "\t";
		cout << call_DB[i].relays << "\t";
		cout << call_DB[i].call_length << "\t";
		cout << call_DB[i].net_cost << "\t";
		cout << call_DB[i].tax_rate << "\t";
		cout << call_DB[i].call_tax << "\t";
		cout << call_DB[i].total_cost << endl;

		out.setf(ios::showpoint);
		out.precision(2);
		out.setf(ios::fixed);
		/********************************************/

		out << call_DB[i].cell_number << "\t";
		out << call_DB[i].relays << "\t";
		out << call_DB[i].call_length << "\t";
		out << call_DB[i].net_cost << "\t";
		out << call_DB[i].tax_rate << "\t";
		out << call_DB[i].call_tax << "\t";
		out << call_DB[i].total_cost << endl;
	}
	cout << endl;
	out.close();
}
//***********************************************************************
// Name: Process
// Precondition:
// Postcondition:
// Description:
//************************************************************************

void Process(call_record call_DB[], const int & count)
{
	int i; // index for the "for" loop..
		   // Remember to use a "for" loop when you know how many items you will be processing. Use the dot operator when you are accessing fields in a record. 
		   // For example, when we need to access the relay field in the first record in the array use call_DB[0].relay   .
	for (i = 0; i < count; i++)
	{
		call_DB[i].net_cost = call_DB[i].relays / 50.0 * .40 * call_DB[i].call_length;
		if (call_DB[i].relays >= 0 && call_DB[i].relays <= 5)
		{
			call_DB[i].tax_rate = 0.01;
		}
		else if (6 <= call_DB[i].relays && call_DB[i].relays <= 11) {
			call_DB[i].tax_rate = 0.03;
		}
		else if (12 <= call_DB[i].relays && call_DB[i].relays <= 20) {
			call_DB[i].tax_rate = 0.05;
		}
		else if (21 <= call_DB[i].relays && call_DB[i].relays <= 50) {
			call_DB[i].tax_rate = 0.08;
		}
		else if (call_DB[i].relays > 50) {
			call_DB[i].tax_rate = 0.12;
		}

		call_DB[i].call_tax = (call_DB[i].net_cost * call_DB[i].tax_rate);

		// ADD THE REST OF THE CODE TO PROCESS a call_DB[i] record
		call_DB[i].total_cost = (call_DB[i].net_cost + call_DB[i].call_tax);
	}
}
int main()
{
	call_record call_DB[SIZE];
	int count = 0;
	Input(call_DB, count); // This function will read all the input stored in a file into the array call_DB 
	Process(call_DB, count); // This function will process each call_record stored in the array call_DB.
	Output(call_DB, count); // This function prints all the fields of every record stored in the array call_DB to an output file.
							// Each record with be printed on a separate line in the output file.

	return 0;
}
