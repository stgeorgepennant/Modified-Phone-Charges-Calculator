
/****SAMPLE PROGRAM HEADER*******************************************************
St George Pennant
Due Date: February 17, 2020
Course:  C0P3014
Assignment:  Program 3
Professor: Sorgente

Description: This program calculates the order tax (orderTax), the net cost (netCost), and the total cost (totalCost) of an online order 
by reading the data for the cell number, item number, location ID, price, and quantity from an input file and displays the results onto 
the screen in columns.

*************************************************************/
#include <iostream> //standard library for i/o
#include <string> // always include this when you use the string class
#include <fstream>  //you must include this library if you wish to do file i/o
using namespace std;

/*********************************************************
//Following is the declaration of a order record
**********************************************************/
class orderRecord
{
public:
	string cellNum;
	string itemNum;
	int quantity;
	double price;
	int locID;
	double taxRate;
	double orderTax;
	double netCost;
	double totalCost;
};

//Declaration/ Prototypes for your functions will go here
//BE SURE TO ADD COMMENTS TO THE FUNCTION PROTOTYPES AND THE FUNCTION DEFINITIONS
//ADD the full comments to the function prototypes (pre and post conditions, and descriptions)
//ADD brief descriptions to the function definitions

void GetInput(ifstream&, orderRecord&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does  


void ProcessData(orderRecord&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does 


void GetTaxRate(double&, int);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does 


void ScreenOutput(const orderRecord&);
//Precondition: State what is true before the function is called.
//Postcondition: State what is true after the function has executed.
//Description:  Describe what the function does 


//HERE IS THE main function, a driver to test your program
int main()
{
	string name;
	cout << "Enter your first name: ";
	cin >> name;
	cout << name << ", Let's get started processing the file data." << endl;

	orderRecord customerData;

	ifstream in;    //declaring an input file stream
	in.open("purchaseData.txt"); //connect to the input file 

	if (in.fail())
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof()) //has not reached the end of the file
		{
			GetInput(in, customerData);
			//call ProcessData
			ProcessData(customerData);
			//call ScreenOutput
			ScreenOutput(customerData);
		}
	}

	in.close();
	cout << name << ", have a nice day! " << endl;

	return  0;
}

//Function Implementations will go here

//Description:  Describe what the function does 
void GetInput(ifstream& in, orderRecord& p_record)
{
	in >> p_record.cellNum;
	//add more code to read the rest of the fields (itemNum, quantity, price and locID) into the 
	//order record, p_record.
	in >> p_record.itemNum;
	in >> p_record.quantity;
	in >> p_record.price;
	in >> p_record.locID;
}


//Description:  Describe what the function does 
void ProcessData(orderRecord& p_record)
{
	//Call the GetTaxRate function to get the tax rate 
	//based on the p_record.locID
	GetTaxRate(p_record.taxRate, p_record.locID);

	//calculate the orderTax, netCost, and totalCost
	//of the p_record, example: p_record.taxRate
	p_record.orderTax = (p_record.price * p_record.quantity * p_record.taxRate);
	p_record.netCost = (p_record.quantity * p_record.price);
	p_record.totalCost = (p_record.netCost + p_record.orderTax);
	
	/* • All double output should be presented with 2 or 4 
		decimal places(see sample output)*/
}


//Description:  Describe what the function does 
void GetTaxRate(double& taxRate, int locID)
{
	//use the location ID to set the tax rate
	if (locID >= 500 && locID <= 530) //500 <= locationID <= 530– TAX rate is 4 % (.04)
		taxRate = .04;

	else if (531 <= locID && locID <= 560) //531 <= locationID <= 560 – TAX rate is 6 % (.06)
		taxRate = 0.06;

	else if (561 <= locID && locID <= 580) //561 <= locationID <= 580– TAX rate is 6.6 % (.066)
		taxRate = 0.066;

	else if (581 <= locID && locID <= 600) //581 <= locationID <= 600– TAX rate is 7 % (.07)
		taxRate = 0.07;

	else if (locID > 600) //locationID > 600 - TAX rate is 8.25 % (.0825)
		taxRate = 0.0825;
	
	else if (locID < 500)  //invalid location, < 500 – is not a valid entry for the locationID(less than 500 is not valid)
		cout << "Invalid location" << endl << endl;
}


//Description:  Describe what the function does 
void ScreenOutput(const orderRecord& p_record)
{

	//set the number of decimal places for doubles
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2); //use any number her for the number of decimal places

	// display the results here
	//cout << p_record.cellNum << "\t"; //\t for tab
	//add more code to print all the fields in the order record
	cout << p_record.cellNum << "\t";
	cout << p_record.itemNum << "\t";
	cout << p_record.quantity << "\t";
	cout << p_record.price << "\t";
	cout << p_record.locID << "\t";

	cout.precision(4);
	cout << p_record.taxRate << "\t";
	
	cout.precision(2);
	cout << p_record.orderTax << "\t";
	cout << p_record.netCost << "\t";
	cout << p_record.totalCost << endl;
}





