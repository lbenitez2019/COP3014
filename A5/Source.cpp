// Course: COP3014
// Date : OCT-7-2022
// Assignment: 4
// Purpose:

// Includes and other compiler directives
#include <iostream>
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

	//overloaded operators
	friend rational operator + (rational a, rational b);
	friend rational operator - (rational a, rational b);
	friend bool operator == (rational a, rational b);
	friend bool operator >= (rational a, rational b);
	friend bool operator <  (rational a, rational b);
	friend bool operator >  (rational a, rational b);
	friend bool operator <= (rational a, rational b);
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

	x1.print_endl();
	x2.print_endl();
	x3.print_endl();

	x3 = x1 + x2;
	x3.print_endl();

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