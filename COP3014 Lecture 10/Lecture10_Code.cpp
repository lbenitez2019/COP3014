/*
COP3014: STRUCTURES as an intro to classes
Instructor: Sareh Taebi, PhD
Date: 10/04/2022
*/

#include <iostream>

using namespace std;

// Structure for a bank certificate of deposit: 
// It's a public data structure (declared outside of any function) and therefore any function can use it
struct CDAccount
{
double balance;			// Current balance
double interest_rate;	// CD APR (annual percentage rate) 
int term;				// Maturity term length (in months)
};


// Other Structs to show the hierarchy in Strucs (nested Structs)
struct Date
{
   short month;			// Month of date (numeric, short integer)
   short day;			// Day   of date (numeric, short integer)
   short year;			// Year  of date (numeric, short integer)
};

struct PersonInfo
{
double height;			// Person height in inches
int weight;				// Person weight in pounds
Date birthday;			// Person date of birth (struct within a struct)
};

//*********************************************************************
// Function prototypes for structures.
//*********************************************************************

void get_data(CDAccount& the_account);
// Input:  CDAccount struct (call by reference)
// Output: Updated struct,
//		   the_account.balance and the_account.interest_rate have been
//         given values that the user entered at the keyboard.

CDAccount make_account(double the_balance, double the_rate, int the_term);
// Input:  balance, rate, term (call by value) 
// Output: Returns an object of type CDAccount, with updated member values

void get_BD(Date& Birthday);
// Input : Birthday struc address 
// Output: Prompt user for date, month and year, and 
//		   store in Birthay struct.  


int main()
{

CDAccount account;		 // Declare variable of type CAcount

get_data(account);       // Prompt user for data to fill account

double rate_fraction, interest; 
rate_fraction = account.interest_rate / 100.0;	// Convert from percent to decimal
interest = account.balance * rate_fraction * (account.term / 12.0);  // Compute interest
account.balance = account.balance + interest;	// Update balance by adding interest.

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
cout << "When your CD matures in " << account.term << " months,\n" << "it will have a balance of $" << account.balance << endl;

CDAccount new_account;
new_account = make_account(10000.00, 5.1, 11);	// Update new_account struct (call by value)

PersonInfo Alice;								// declare Alice of type PersonInfo
get_BD(Alice.birthday);							// function call


Alice = {50, 100, Alice.birthday};
cout << "Alice's height: " << Alice.height << endl;
cout << "Alice's weight: " << Alice.weight << endl;
cout << "Alice's bday  : " << Alice.birthday.day << '/' << Alice.birthday.month << '/' << Alice.birthday.year ;


//Note all the initializations. what happens here?
Date due_date1 = {12, 21};
// Date due_date2 = {12, 21, 20, 22};
Date due_date3 = {12, 21, 22};

return 0;

}

//Uses iostream
void get_data(CDAccount& the_account)
{
cout << "Enter account balance: $";
cin >> the_account.balance;
cout << "Enter account interest rate (in percentage): ";
cin >> the_account.interest_rate;
cout << "Enter the number of months until maturity (must be 12 or fewer months): ";
cin >> the_account.term;
}

//returns a value of type CDAccount
CDAccount make_account(double the_balance, double the_rate, int the_term)
{
CDAccount temp;
temp.balance = the_balance;
temp.interest_rate = the_rate;
temp.term = the_term;
return temp;
}

void get_BD(Date& Birthday)
{
cout << "Enter birth day: ";
cin >> Birthday.day;
cout << "Enter birth month: ";
cin >> Birthday.month;
cout << "Enter birth year: ";
cin >> Birthday.year;
}
