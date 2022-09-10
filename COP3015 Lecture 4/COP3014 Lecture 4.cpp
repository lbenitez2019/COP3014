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
