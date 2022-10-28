// Course: COP3014
// Date : OCT-28-2022
// Assignment: lab 2

// 1 Generate a class called Money which represents amounts of U.S. currency
// 
// 2 value is implemented  as  a  single  integer  value  that  represents  the  amount  of  money  as  if  it  were
// converted to all pennies For example, $9.95 would be stored as the value 995.
// 
// 3 The class must have the following constructors:
// 3a Money(long dollars, int cents);
// Initializes  the  object  so  its  value  represents  an  amount  with  the 
// dollarsand cents given by the arguments.If the amount is negative,
// then both dollarsand cents must be negative.
// 
// 3b Money(long dollars);
// Initializes the object so its value represents $dollars.00.
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
//	Money laptop;
//Laptop.output(cout);   //1

//laptop.output();  //2 is the same as 1 (overloaded definition of output)

//laptop.output(outs);     //send to any output stream (file)

//6 The class has a getter function with the following prototype.It also has a setter function
//that you can define.
//double get_value() const;
//The class has an input function called input which takes in an amount of money, including
//a dollar sign through its input stream ins.Notation for negative amounts is - $100.00.The
//value of the calling object has been set to the amount of money read from the input stream.

//void input(istream & ins);

//Inside the main, test all the class functionalities with objects of your choice.



// Includes and other compiler directives
#include <iostream>
using namespace std;


// Class Definitions, function prototypes

class money
{
public:








private:


	// getter functions



	// Other/Special functions


	// -- Private variables  --


	// -- Private constants --


};



int main()
{
	// Variable declarations
	


}

