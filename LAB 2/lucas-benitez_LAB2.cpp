// Course: COP3014
// Date : OCT-28-2022
// Assignment: lab 2

// 1! Generate a class called Money which represents amounts of U.S. currency
// 
// 2! value is implemented  as  a  single  integer  value  that  represents  the  amount  of  money  as  if  it  were
// converted to all pennies For example, $9.95 would be stored as the value 995.
// 
// 3 The class must have the following constructors:
// 3a Money(long dollars, int cents);
// Initializes  the  object  so  its  value  represents  an  amount  with  the 
// dollarsand cents given by the arguments.If the amount is negative,
// then both dollarsand cents must be negative.
// 
// 3b Money(long dollars);
// Initializes the object so its value represents $dollars.00
// 
// 3c Money();
// Initializes the object so its value represents $0.00.
// 
// 4 The class Money must have the friend functions : 
// equal - returns true if the two objects amount1 and amount2 have values that represent equal amounts of money
// add - returns a Money object whose value is the sum of the values of its two arguments
// subtract - take two arguments of type Money & returns a value of type Money whose value is the value of the first argument minus the value of the second argument
// 
// 5 The  class  also  has  overloaded  function  name  output  so  that  there  are  two  versions  of
//	output One version takes an output stream reference argument, and the other version of
//	output takes no arguments and sends its output to the screen
// 
// 6 The class has a getter function with the following prototype.It also has a setter function
// that you can define.
// double get_value() const;
// The class has an input function called input which takes in an amount of money, including
// a dollar sign through its input stream ins.Notation for negative amounts is - $100.00.The
// value of the calling object has been set to the amount of money read from the input stream.
// void input(istream & ins);
// Inside the main, test all the class functionalities with objects of your choice.



// Includes and other compiler directives
#include <iostream>	
#include <fstream>
using namespace std;

	

// Class Definitions, function prototypes

class money
{
public:
	int cents;

	// constructors
	money(long newdollars, int newcents);
	money(long newdollars);
	money();

	// member functions
	void output();
	void output(ofstream& os);
	void input(istream& ins);

	// getters and setters
	int get_cents();
	void set_cents(int temp_cents);

	//friend functions
	friend bool equal(money const amount1, money const amount2);
	friend money add(money amount1, money amount2);
	friend money subtract(money amount1, money amount2);

private:

};

int main()
{
	// filestream variables
	ofstream out_stream;
	ifstream in_stream;


	// money objects
	money value1(1,1);
	money value2(1);
	money value3;
	money x(6);

	equal(value1, value2);
	x=add(value1, value2);
	x=subtract(value1, value2);

	// Open WRITE stream to file money.txt
	out_stream.open("money.txt");      // open the stream / file for WRITING  
	if (out_stream.fail())
	{
		cout << "Could not open file money.txt" << endl;
		exit(3);                    // Indicate error code 3
	}

	//	// Open READ stream to file money.txt
	//in_stream.open("money.dat");      // open the stream / file for WRITING
	//if (in_stream.fail())
	//{
	//	cout << "Could not open file money.txt" << endl;
	//	exit(3);                    // Indicate error code 3
	//}
	
	x.output();
	x.output(out_stream);
	out_stream << 99999;

	out_stream.close();             // close the file stream

}

// constructor definitions
money::money(long newdollars, int newcents)
{
// Initializes  the  object  so  its  value  represents  an  amount  with  the 
// dollarsand cents given by the arguments.If the amount is negative,
// then both dollarsand cents must be negative.
	cents = newcents + (newdollars*100);
	cout << "cents = " << cents << endl;
};

money::money(long newdollars) 
{
	// Initializes the object so its value represents $dollars.00
	cents = newdollars * 100;
	cout << "dollars = " << cents << endl;

};

money::money()
{
	// Initializes the object so its value represents $0.00.
	set_cents(0);
	cout << "default = " << cents << endl;
};


// friend function definitions
bool equal(money const amount1, money const amount2)
{
	// returns true if the two objects amount1 and amount2 have values that represent equal amounts of money
	if (amount1.cents == amount2.cents)
	{
		cout << " objects are equal " << endl;
		return 1;
	}
	else
	{
		cout << "objects are not equal " << endl;
		return 0;
	}
	
};

money add(money amount1, money amount2)
{
	//add - returns a Money object whose value is the sum of the values of its two arguments
	money x;
	cout << "using getter" << amount1.get_cents() << endl;

	x.cents = amount1.cents + amount2.cents;
	cout << "add" << amount1.cents << "  " << amount2.cents << endl;
	cout << "sum =" << x.cents;
	return x;
	
};

money subtract(money amount1, money amount2)
{
// subtract - take two arguments of type Money & returns a value of type Money whose value is the value of the first argument minus the value of the second argument
	money x;
	x.cents = amount1.cents - amount2.cents;
	cout << "subtract" << amount1.cents << "  " << amount2.cents << endl;
	cout << "difference =" << x.cents;
	return x;
};

//getter function definition
int money::get_cents()
{
	return cents;
};

//setter function definition
void money::set_cents(int temp_cents)
{
	cents = temp_cents;
};

//member function definitions
void money::output()
{
	cout << "output()" << cents;
};

void money::output(ofstream& os)
{
	os << cents;
};