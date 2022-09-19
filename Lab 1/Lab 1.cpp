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
    double hs; // Hat size
    double js; // Jacket size
    double ws; // Waist size
    int af;    // Adjustment factor

    int lc = 1; // Loop control
    while (lc == 1)
    {
        // Prompt for h, w, and a
        cout << "Height (in): ";
        cin >> h;
        cout << "Weight (lbs): ";
        cin >> w;
        cout << "Age (yrs): ";
        cin >> a;
        
        // Calc Hat Size
        hs = w / h * 2.9;
        cout << "Hat Size: " << hs << endl;

        // Calc Jacket Size
        af = ((a - 30) / 10);
        cout << "af1 = " << af << endl;
        js = (h * w / 288.0) + (af / 8.0);
        cout << "Jacket Size: " << js << endl;

        // Calc Waist Size
        af = ((a - 28) / 2);
        cout << "af2 = " << af << endl;
        ws = (w / 5.7) + (af / 10.0);
        cout << "Waist Size: " << ws << endl;

        cout << "Continue? (1=yes, 0=no) ";
        cin >> lc;
    }

    return 0;
}
