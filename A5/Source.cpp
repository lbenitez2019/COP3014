// Course: COP3014
// Date : OCT-7-2022
// Assignment: 5
// Purpose:

// Includes and other compiler directives
#include <iostream>
#include <fstream>
using namespace std;

// Class Definitions, function prototypes

class rational
{
public:
	// -- Public functions --
	//constructors
	rational(int new_n, int new_d);
	rational(int new_n);
	rational();

	void print();
	void print_endl();

	// insertion / extraction operators overloaded functions
	friend ofstream& operator << (ofstream& output, rational& x);
	friend ifstream& operator >> (ifstream& input, rational& x);	

	//overloaded operators
	friend rational operator + (rational a, rational b);
	friend rational operator - (rational a, rational b);	
	friend rational operator * (rational a, rational b);
	friend rational operator / (rational a, rational b);
	friend bool operator == (rational a, rational b);
	friend bool operator >= (rational a, rational b);
	friend bool operator <  (rational a, rational b);
	friend bool operator >  (rational a, rational b);
	friend bool operator <= (rational a, rational b);
	friend rational operator - (rational a);
private:
	// -- Private functions --

	// setter functions

	// getter functions

	// -- Private variables  --
	int n;
	int d;

	// -- Private constants --
};



int main()
{
	rational x1(9);
	rational x2(1,7);
	rational x3;

	//filestream declarations
	ofstream output;
	ifstream input;

	x1.print_endl();
	x2.print_endl();
	x3.print_endl();

	x3 = x1 + x2;
	x3.print_endl();

	//testing > boolean function
	x1.print(); cout << " > "; x2.print();
	if (x1 > x2)
		cout << ": TRUE" << endl;
	else
		cout << ": FALSE" << endl;

	//testing < boolean function
	x1.print(); cout << " < "; x2.print();
	if (x1 < x2)
		cout << ": TRUE" << endl;
	else
		cout << ": FALSE" << endl;

	//testing >= boolean function
	x1.print(); cout << " >= "; x2.print();
	if (x1 >= x2)
		cout << ": TRUE" << endl;
	else
		cout << ": FALSE" << endl;
	
	//testing <= boolean function
	x1.print(); cout << " <= "; x2.print();
	if (x1 <= x2)
		cout << ": TRUE" << endl;
	else
		cout << ": FALSE" << endl;
		
	//testing == boolean function
	x1.print(); cout << " == "; x2.print();
	if (x1 == x2)
		cout << ": TRUE" << endl;
	else
		cout << ": FALSE" << endl;
		
	//testing unary - overloaded function
	x1.print(); cout << " unary - = "; 
	x1 = -x1;
	x1.print_endl();	
	x1 = -x1;
	
	x2.print(); cout << " unary - = "; 
	x2 = -x2;
	x2.print_endl();
	x2 = -x2;

	//testing + overloaded function
	x3 = x1 + x2;
	x1.print(); cout << " + "; x2.print(); cout << " = "; x3.print(); cout << endl;
	
	//testing - overloaded function
	x3 = x1 - x2;
	x1.print(); cout << " - "; x2.print(); cout << " = "; x3.print(); cout << endl;	

	//testing * overloaded function
	x3 = x1 * x2;
	x1.print(); cout << " * "; x2.print(); cout << " = "; x3.print(); cout << endl;

	//testing / overloaded function
	x3 = x1 / x2;
	x1.print(); cout << " / "; x2.print(); cout << " = "; x3.print(); cout << endl;

	output.open("rational_out.txt");
	output << "test";

	input.open("rational_in.txt");
	input >> x1;
	x1.print();


	return 0;
}

//class function definitions
void rational::print()
{
	cout << n << "/" << d;
};

void rational::print_endl()
{
	cout << n << "/" << d << endl;
};


// constructor definitions
rational::rational(int new_n, int new_d)
{
	n = new_n;
	d = new_d;
};

rational::rational(int new_n)
{
	n = new_n;
	d = 1;
};

rational::rational()
{
	n = 0;
	d = 1;
};

//overloaded operator function definitions
rational operator + (rational x, rational y)
{
	rational temp;
    
	temp.n = (x.n * y.d + x.d * y.n);
	temp.d = (x.d * y.d);

	return temp;

};

//overloaded operator function definitions
rational operator - (rational x, rational y)
{
	rational temp;
    
	temp.n = (x.n * y.d - x.d * y.n);
	temp.d = (x.d * y.d);

	return temp;
};

//overloaded operator function definitions
bool operator == (rational x, rational y)
{
	return (x.n * y.d) == (y.n * x.d);
};

//overloaded operator function definitions
bool operator >= (rational x, rational y)
{
	return (x.n * y.d) >= (y.n * x.d);
};

//overloaded operator function definitions
bool operator > (rational x, rational y)
{
	return (x.n * y.d) > (y.n * x.d);
};

//overloaded operator function definitions
bool operator < (rational x, rational y)
{
	return (x.n * y.d) < (y.n * x.d);
};

//overloaded operator function definitions
bool operator <= (rational x, rational y)
{
	return (x.n * y.d) <= (y.n * x.d);
}

//overloaded operator function definitions
rational operator-(rational x)
{
	x.n = x.n * - 1;
	x.d = x.d * - 1;
	return x;
};

//overloaded operator function definitions
rational operator * (rational x, rational y)
{
	rational temp;

	temp.n = (x.n * y.n);
	temp.d = (x.d * y.d);
	return temp;
};

//overloaded operator function definitions
rational operator / (rational x, rational y)
{
	rational temp;

	temp.n = (x.n * y.d);
	temp.d = (y.n * y.d);
	return temp;
};

ofstream& operator << (ofstream& output, rational& x)
{
	output << x.n << "/" << x.d;
	return output;
};


ifstream& operator >> (ifstream& input, rational& x)
{
	char c;

	input >> x.n;
	input >> c;
	input >> x.d;

	return input;
};