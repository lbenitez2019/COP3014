// Course: COP3014
// Date : OCT-30-2022
// Author: Lucas Benitez
// Assignment: lab 2

// 1 Generate a class called Money which represents amounts of U.S. currency
// 
// 2 value is implemented  as  a  single  integer  value  that  represents  the  amount  of 
//  money  as  if  it  were converted to all pennies For example, $9.95 would be stored as the value 995.
// 
// 3 The class must have the following constructors:
// 3a Money(long dollars, int cents);
//    Initializes  the  object  so  its  value  represents  an  amount  with  the 
//    dollarsand cents given by the arguments.If the amount is negative,
//    then both dollarsand cents must be negative.
// 
// 3b Money(long dollars);
//    Initializes the object so its value represents $dollars.00
// 
// 3c Money();
//    Initializes the object so its value represents $0.00.
// 
// 4 The class 'money' must have the friend functions: 
//      equal	 - returns true if the two objects amount1 and amount2 have values that represent equal 
//				   amounts of money
//      add		 - returns a Money object whose value is the sum of the values of its two arguments
//      subtract - take two arguments of type Money & returns a value of type Money whose value is the 
//                 value of the first argument minus the value of the second argument
// 
// 5 The  class  also  has  overloaded  function  name  'output'  so  that  there  are  two  versions  of
//	 'output': 
//	  - one version takes an 'output' stream reference argument, and 
//    - the other version of 'output' takes no arguments and sends its output to the screen
// 
// 6 The class has a getter/setter functions with the following prototype.
// 7 The class has an input function called 'input' which takes in an amount of money, including
//   a dollar sign through its input stream ins.Notation for negative amounts is - $100.00.The
//   value of the calling object has been set to the amount of money read from the input stream.
//   void input(istream & ins);
// 8  Inside the main, test all the class functionalities with objects of your choice.


// Includes and other compiler directives
#include <iostream>	
#include <fstream>
using namespace std;

// Class Definitions, function prototypes
class money
{
public:
	// constructors
	money(long newdollars, int newcents);
	money(long newdollars);
	money();

	// member functions
	void output();
	void output(ofstream& os);
	void input(istream& ins);

	//friend functions
	friend bool equal(money const amount1, money const amount2);
	friend money add(money amount1, money amount2);
	friend money subtract(money amount1, money amount2);

	friend money operator + (money amount1, money amount2);	
	friend money operator - (money amount1, money amount2);
	friend bool operator == (money amount1, money amount2);
	friend bool operator >= (money amount1, money amount2);
	friend bool operator < (money amount1, money amount2);
	friend bool operator > (money amount1, money amount2);
	friend bool operator <= (money amount1, money amount2);

	// getters and setters
	int get_cents();
	void set_cents(int temp_cents);

private:
	// variables
	int cents;
	
};

int main()
{
	// filestream variables
	ofstream out_stream;
	ifstream in_stream;

	// money objects
	money value1(3,0);
	money value2(3);
	money value3;
	money x(6);

	// test that constructors built "money" objects properly
	cout << "\ntest constructor with 2 input parameters. ";
	value1.output();
	cout << "\ntest constructor with 1 input parameter. ";
	value2.output();
	cout << "\ntest constructor with 0 input parameters. ";
	value3.output();
	cout << "\ntest constructor with 1 input parameter. ";
	x.output();

	cout << "-----------------------------------------------------" << endl;
	cout << "Testing with: value1=" << value1.get_cents() << " and value2=" << value2.get_cents() << endl;
	cout << "-----------------------------------------------------" << endl << endl;

	// Call and test 'equal' function
	if(equal(value1, value2))
		cout << "equal() function: value1 and value 2 are equal " << endl << endl;
	else
		cout << "equal() function: value1 and value 2 are NOT equal " << endl << endl;
	
	// Call and test 'add' function
	x=add(value1, value2);
	cout << "add() function, value1 + value 2: ";
	x.output(); cout << endl;

	// Call and test 'subtract' function
	x=subtract(value1, value2);
	cout << "subtract() function, value1 - value 2: ";
	x.output(); cout << endl;

		// Call and test overloaded operators
	x=value1 + value2;
	cout << "\n'+' operator, value1 + value2: ";
	x.output();	

	x=value1 - value2;
	cout << "\n'-' operator, value1 - value2: ";
	x.output();
	
	if (value1 == value2)
		cout << endl << "'==' operator : " << value1.get_cents() << " == " << value2.get_cents() << endl;
	else
		cout << endl << "'==' operator: " << value1.get_cents() << " NOT == " << value2.get_cents() << endl;	

	if (value1 > value2)
		cout << endl << "'>' operator: " << value1.get_cents() << " > " << value2.get_cents() << endl;
	else
		cout << endl << "'>' operator: " << value1.get_cents() << " NOT > " << value2.get_cents() << endl;
	
	if (value1 >= value2)
		cout << endl << "'>=' operator: " << value1.get_cents() << " >= " << value2.get_cents() << endl;
	else
		cout << endl << "'>=' operator: " << value1.get_cents() << " NOT >= " << value2.get_cents() << endl;
	
	if (value1 < value2)
		cout << endl << "'<' operator: " << value1.get_cents() << " < " << value2.get_cents() << endl;
	else
		cout << endl << "'<' operator: " << value1.get_cents() << " NOT < " << value2.get_cents() << endl;
	
	if (value1 <= value2)
		cout << endl << "'<=' operator: " << value1.get_cents() << " <= " << value2.get_cents() << endl;
	else
		cout << endl << "'<=' operator: " << value1.get_cents() << " NOT <= " << value2.get_cents() << endl;





	// Open WRITE stream to file money.txt
	out_stream.open("money.txt");      // open the stream for WRITING  
	if (out_stream.fail())
	{
		cout << "Could not open file money.txt" << endl;
		exit(3);                    // Indicate error code 3
	}
	
	// Call and test 'output' function with 1 input parameter, to write to file
	x.output(out_stream);

	// Open READ stream to file money.txt
	in_stream.open("money.txt");      // open the stream for READING
	if (in_stream.fail())
	{
		cout << "Could not open file money.txt" << endl;
		exit(3);                    // Indicate error code 3
	}
	
	// Call and test 'input' function with 1 input parameter, to read from file
	x.input(in_stream);

	out_stream.close();             // close the file stream
	in_stream.close();				// close the file stream
}

//----------------------------------------------------------------------------
// Constructor definitions
//----------------------------------------------------------------------------
money::money(long newdollars, int newcents)
{
// Initializes  the  object  so  its  value  represents  an  amount  with  the 
// dollars and cents given by the arguments. If the amount is negative,
// then both dollarsand cents must be negative.
	cents = newcents + (newdollars*100);
};

money::money(long newdollars) 
{
	// Initializes the object so its value represents $dollars.00
	cents = newdollars * 100;
};

money::money()
{
	// Initializes the object so its value represents $0.00.
	set_cents(0);
};


//----------------------------------------------------------------------------
// friend function definitions
//----------------------------------------------------------------------------

bool equal(money const amount1, money const amount2)
{
	// 'equal' returns true if the two objects, amount1 and amount2, have values that 
	// represent equal amounts of money
	if (amount1.cents == amount2.cents)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
};

money add(money amount1, money amount2)
{
	// 'add' - returns a 'money' object whose value is the sum of the values of its two input arguments
	money x;

	x.cents = amount1.cents + amount2.cents;
	return x;
	
};

money operator + (money amount1, money amount2)
{
	// 'add' - returns a 'money' object whose value is the sum of the values of its two input arguments
	money x;

	x.cents = amount1.cents + amount2.cents;
	return x;
	
};

money operator - (money amount1, money amount2)
{
	money x;

	x.cents = amount1.cents - amount2.cents;
	return x;
	
};

bool operator == (money amount1, money amount2)
{

	 return (amount1.cents == amount2.cents);
	
};

bool operator > (money amount1, money amount2)
{

	 return (amount1.cents > amount2.cents);
	
};

bool operator >= (money amount1, money amount2)
{

	 return (amount1.cents >= amount2.cents);
	
};
bool operator < (money amount1, money amount2)
{

	 return (amount1.cents < amount2.cents);
	
};
bool operator <= (money amount1, money amount2)
{

	 return (amount1.cents <= amount2.cents);
	
};

money subtract(money amount1, money amount2)
{
	// 'subtract' - take two arguments of type 'money' 
	// returns a value of type Money whose value is the first argument minus the second argument
	money x;
	x.cents = amount1.cents - amount2.cents;
	return x;
};

//----------------------------------------------------------------------------
// getters/setters function definitions
//----------------------------------------------------------------------------
int money::get_cents()
{
	return cents;
};

//setter function definition
void money::set_cents(int temp_cents)
{
	cents = temp_cents;
};


//----------------------------------------------------------------------------
// other 'money' class member function definitions
//----------------------------------------------------------------------------
void money::output()
{
	cout << "cents = " << cents << endl; // prints value of object to screen
};

void money::output(ofstream& os)
{
	os << cents;  // Writes value of 'cents' to file
};

void money::input(istream& ins)
{
	ins >> cents;  // Reads value from file, and stores in 'cents'
	cout << "\nvalue read from file = " << cents;  
};