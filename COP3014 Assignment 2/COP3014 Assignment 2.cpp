/*
COP3014: Programmming II
Assignment: 2
Purpose: Loan Calculator
Instructor: Sareh Taebi
Author: Lucas Benitez
*/
#include <iostream>
#include <string>       // Needed for type string
#include <cmath>        // Needed for pow()
#include <iomanip>

using namespace std;

int main()
{
    // Variable declarations
    double P;   // Mortgage principal loan amount
    double r;   // Montly interest rate (annual interest rate / 12) 
    int n;      // Number of montly payments over loan’s lifetime (e.g., loan years * 12) 
                // Example: for a 2 year loan, n = 24
    double M;   // Monthly Payment (to be calculated)
                // Example: for 10% interest rate, r = 0.1/12 per month

    // Formula:  𝑀 = 𝑃 * (𝑟 * (1 + 𝑟)^𝑛) / ((1 + 𝑟)^𝑛 − 1)
    
    // Set number formatting for cout
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // Prompt for loan amount
    cout << "Enter total loan amount (in $1000's): "; 
    cin >> P;
    P *= 1000; // convert loan value to thoudands value
    cout << "P = $" << P << endl;

    // Prompt for annual interest rate
    cout << "Enter annual interest rate: ";
    cin >> r;
    r = r / 100; // convert r to a percent
    cout << "Interest rate = " << r << " (or " << r*100 << "%) " << endl;
    r = r / 12; // convert r to a monthly rate
    
    // Prompt for loan term length
    cout << "Enter the loan term length in years: ";
    cin >> n; 
    n *= 12; // convert years to months / payment periods
    cout << "No. of payments: " << n << endl;
    
    // Calculate the monthly payment for each month
    M = pow(1+r, n) * P * r;
    M = M / (pow(1 + r, n) - 1);
    cout << "first payment : $" << M << endl;

    double ip; // interest payment for each month
    double pp; // principal payment for each month month
    double rm = P; // remaining balance for each moth

    // Initial nalue of n is number of months in loan
    while (n > 0)
    {
        ip = r * rm;  // calculate interest payment for this month
        pp = M - ip; // calculate principal payment for this month
        rm -= pp;     // update the remaining balance, deduct principal
        cout << "Mth:" << n << setw(10) << " Int:$" << ip << setw(10) << " Ppl:$" << pp << setw(10) << " Rem:$" << rm << endl;
        
        n--; // decrement loop counter (month)
    }


    /*
    // Example B
    f = (9 / 5) * c + 32.1;
    cout << "the temp is: " << f << endl;
    // Example B end

    // Example A
    int q = 2;
    cout << "start " << endl;
    if (q <= 3)
        if (q != 0)
            cout << "Hello from the second if." << endl;
        else
            cout << "Hello from the else." << endl;
    cout << "End." << endl;

    cout << "Start again." << endl;
    if (q > 3)
        if (q != 0)
            cout << "Hello from the second 2nd if." << endl;
        else
            cout << "Hello from the second else." << endl;
    cout << "End again." << endl;
    // Example A end

    cout << "the number is: " << number << endl;
    cout << "Enter two initials, without any periods:\n";
    cin >> symbol1 >> symbol2;
    cout << "The two initials are:\n";
    cout << symbol1 << symbol2 << endl;
    cout << "Once more with a space:\n";
    symbol3 = ' ';
    cout << symbol1 << symbol3 << symbol2 << endl;
    cout << "That's all.\n";
    //program II : string practice
    string middle_name, pet_name;
    string alter_ego_name;
    cout << "Enter your middle name and the name of your pet.\n";
    cin >> middle_name;
    cin >> pet_name;
    alter_ego_name = pet_name + " " + middle_name;
    cout << "The name of your alter ego is ";
    cout << alter_ego_name << "." << endl;
    //program III : other data types
    auto x = 2.4 * 10;
    uint16_t y = 366;
    bool hi = 2;
    cout << "\ndata types " << x << "\t" << sizeof(y) << "\t" << hi << endl;
    //program IV: Arithmetic
    double divisor, dividend, quotient;
    divisor = 3.0;
    dividend = 5.0;
    quotient = dividend / divisor;
    cout << "\narithmetic result: " << quotient << endl;
    */

    return 0;
}
