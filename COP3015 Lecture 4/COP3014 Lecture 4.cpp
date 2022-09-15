/*
COP3014
Lecture 04: switch statements, blocks, program style (programs taken from "Problem
Solving with C++", Walter Savitch
Instructor: Sareh Taebi
Date: 09/06/2022
*/
#include <iostream>
using namespace std;
int main()
{

    // Fragment 1 
    for (int count = 1; count < 5; count = count + 1)
        cout << (2 * count) << " ";
    cout << endl;
    // Fragment 1 end

    //Fragment 2    
    int number = 2;
    int value_produced = 2 * number++;
    cout << "here it is: " << value_produced << endl;
    // Fragment 2 end

    // Fragment 3
    int num = (1 / 3) * 3;
    cout << "(1/3) * 3 is equal to " << num << endl;
    // Fragment 3

    // Fragment 4
    double price = 78.5;
    //cout.setf(ios::showpoint);
    //cout.setf(ios::fixed);
    //cout.precision(4);
    cout << "the price is: " << price << endl;

    // Fragment 4 end

    // Fragment 5
    double Q1 = 3.0 / 4.0 + 3 + (2/5);
    cout << "The value of Q1 is: " << Q1 << endl;
    // Frangment 5 end

    // fragment 6
    int Q2 = 98;
    if ( 19 < Q2 && 99 > Q2)
    {
        cout << "Q2 is inside range " << endl;
    }
    else
    {
        cout << "Q2 is outside range " << endl;
    }
    // fragment 6 end

    // fragment 7
    int i1;
    for (i1 = 9; i1 < 110; i1 += 5)
    {
        if (i1 > 19 && i1 < 99)
        {
            cout << "|  " << i1 << " is inside the range." << endl;
        }
        else
        {
            cout << i1 << " is outside the range." << endl;
        }
    }
    // fragment 7 end

    // program style and use of const identifier for constant numbers
    const double NORMAL = 98.6; //degrees Fahrenheit
    double temperature;
    cout << "Enter your temperature: ";
    cin >> temperature;
    if (temperature > NORMAL)
    {
        cout << "You have a fever.\n";
        cout << "Drink lots of liquids and get to bed.\n";
    }
    else
    {
        cout << "You don't have a fever.\n";
        cout << "Go study.\n";
    }
    //topic: blocks this sample code is for sake of understanding only and should be treated as a programming technique
        int x = 1;
    cout << x << endl;
    {
        cout << x << endl;
        int x = 2;
        cout << x << endl;
    }
    cout << x << endl;
    //switch statement example, note use of default and break!
    char grade;
    cout << "Enter your midterm grade and press Return: ";
    cin >> grade;
    switch (grade)
    {
    case 'A':
        cout << "Excellent. "
            << "You need not take the final.\n";
        break;
    case 'B':
        cout << "Very good. ";
        grade = 'A';
        cout << "Your midterm grade is now "
            << grade << endl;
        break;
    case 'C':
        cout << "Passing.\n";
        break;
    case 'D':
    case 'F':
        cout << "Not good. "
            << "Go study.\n";
        break;
    default:
        cout << "That is not a possible grade.\n";
    }
    cout << "End of midterm grade curve.\n";
    return 0;
}
