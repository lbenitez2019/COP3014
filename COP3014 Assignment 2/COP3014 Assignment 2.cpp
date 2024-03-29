﻿/*
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
    double P;           // Mortgage principal loan amount
    double r;           // Montly interest rate (annual interest rate / 12) 
    int n;              // Number of montly payments over loan’s lifetime (e.g., loan years * 12) 
                        // Example: for a 2 year loan, n = 24
    double M;           // Monthly Payment (to be calculated)
                        // Example: for 10% interest rate, r = 0.1/12 per month

    // Formula:  𝑀 = 𝑃 * (𝑟 * (1 + 𝑟)^𝑛) / ((1 + 𝑟)^𝑛 − 1)
    
    // Set number formatting for cout
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // Prompt for loan amount
    cout << "Enter total loan amount (in $1000's): "; 
    cin >> P;
    P *= 1000;          // convert loan value to thoudands value
    cout << "P = $" << P << endl;

    // Prompt for annual interest rate
    cout << "Enter annual interest rate: ";
    cin >> r;
    r = r / 100;        // convert r to a percent
    cout << "Interest rate = " << r << " (or " << r*100 << "%) " << endl;
    r = r / 12;         // convert r to a monthly rate
    
    // Prompt for loan term length
    cout << "Enter the loan term length in years: ";
    cin >> n; 
    n *= 12;            // convert years to months / payment periods
    cout << "No. of payments: " << n << endl;
    
    // Calculate the monthly payment for each month
    M = pow(1+r, n) * P * r;
    M = M / (pow(1 + r, n) - 1);
    cout << "first payment : $" << M << endl;

    // Additional variables to calculate and display
    double ip;          // interest payment for each month
    double pp;          // principal payment for each month month
    double rm = P;      // remaining balance for each moth

    // Loop counter
    int lc = 1;         // incremented until it reaches total months in loan 
    
    // Table header
    //        123 123456789012 123456789012 123456789012
    cout << "--------------------------------------------" << endl;
    cout << "|Mth|  Int Pmt.  |  Pr Pmt.   |  Rem Bal.  |" << endl;
    cout << "--------------------------------------------" << endl;

    system("PAUSE");
    // Display and tabulation loop 
    while (lc <= n)
    {
        ip = r * rm;    // calculate interest payment for this month
        pp = M - ip;    // calculate principal payment for this month
        rm -= pp;       // update the remaining balance, deduct principal
        // cout << "Mth:" << lc << setw(10) << " Int:$" << ip << setw(10) << " Ppl:$" << pp << setw(10) << " Rem:$" << rm << endl;
        setfill('.');

        cout << setfill(' ') << setw(3) << lc;
        cout << "  $"    << setfill(' ') << setw(10) << ip;
        cout << "  $" << setfill(' ') << setw(10) << pp;
        cout << "  $" << setfill(' ') << setw(10) << rm << endl;
        
        lc++;           // increment loop counter (month)
    }

    system("PAUSE");
    return 0;
}
