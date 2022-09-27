/*
COP3014: Programmming II
Assignment: Lab 1
Purpose: Clothes Sizing Tool
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
    double h;  // Height (in)
    double w;  // Weight (lbs)
    double a;  // Age (yrs)
    double hs; // Hat size (computed)
    double js; // Jacket size (computed)
    double ws; // Waist size (computed)
    int af;    // Adjustment factor (needed for intermediate computation)

    char lc = 'y'; // Outer loop control
    while (lc == 'y' || lc == 'Y')
    {
        // Prompt for inputs h, w, and a
        cout << "Height (in): ";
        cin >> h;
        cout << "Weight (lbs): ";
        cin >> w;
        cout << "Age (yrs): ";
        cin >> a;
        
        
        int lc2 = a + 10; // inner loop control = input age + 10 years. 
        
        // Table Header
        cout << "---------------------------------------------" << endl;
        cout << "| Age | Hat Size | Jacket Size | Waist Size | " << endl;
        cout << "---------------------------------------------" << endl;

        while(a<=lc2)
        {
        // Calc Hat Size
        hs = w / h * 2.9;

        // Calculate Jacket Size
        af = ((a - 30) / 10);
        js = (h * w / 288.0) + (af / 8.0);

        // Calculate Waist Size
        af = ((a - 28) / 2);
        ws = (w / 5.7) + (af / 10.0);

        // Specify NO fixed notation or decimal point only for age
        cout.unsetf(ios::fixed);
        cout.unsetf(ios::showpoint);

        // Print out age
        cout << setfill(' ') << setw(5) << a;   
        
        // Set numerical format for table to decimal point w/ 2 siggnificant digits
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        // Print out Hat/Jacket/Waist size
        cout << setfill(' ') << setw(10) << hs;
        cout << setfill(' ') << setw(13) << js;
        cout << setfill(' ') << setw(13) << ws << endl;

        a += 1; // increment age by 1
        }

        cout << "Continue? (y/n) ";
        cin >> lc;
    }

    return 0;
}
