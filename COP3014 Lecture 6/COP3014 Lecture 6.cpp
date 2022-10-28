/*
COP3014
Lecture 06: Functions, call by value, library functions
Date: 09/13/2022
*/
// Compiler Directives
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

// Local declarations
const double PI = 3.14159;          //global variable! All functions can use it
double total_cost(int , double );
//Computes the total cost, including 5% sales tax,
//on number_par items at a cost of price_par each.
double area(double radius);
//Returns the area of a circle with the specified radius.
double volume(double radius);
//Returns the volume of a sphere with the specified radius.

int main()
{
    //sample use of random number generators
    cout << "#################PROGRAM 0##############" << endl;
    (time(0));
    for (int i = 0; i < 10; i++)
        cout << "die roll :" << (rand() % 6) + 1 << endl << endl;
    //program that allows us to practice call-by-value functions
    double price, bill;
    int number;
    cout << "#################PROGRAM I##############" << endl;
    cout << "Enter the number of items purchased: ";
    cin >> number;
    cout << "Enter the price per item $";
    cin >> price;
    bill = total_cost(number, price);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << number << " items at "
        << "$" << price << " each.\n"
        << "Final bill, including tax, is $" << bill
        << endl << endl;
    //another problem to practice functions
    double radius_of_both, area_of_circle, volume_of_sphere;
    cout << "#################PROGRAM II##############" << endl;
    cout << "Enter a radius to use for both a circle\n"
        << "and a sphere (in inches): ";
    cin >> radius_of_both;
    area_of_circle = area(radius_of_both);
    volume_of_sphere = volume(radius_of_both);
    cout << "Radius = " << radius_of_both << " inches\n"
        << "Area of circle = " << area_of_circle
        << " square inches\n"
        << "Volume of sphere = " << volume_of_sphere
        << " cubic inches\n";
    return 0;
}
double total_cost(int number_par, double price_par)
{
    const double TAX_RATE = 0.05; //5% sales tax
    double subtotal;
    subtotal = price_par * number_par;
    return (subtotal + subtotal * TAX_RATE);
}
double area(double radius)
{
    return (PI * pow(radius, 2));
}
double volume(double radius)
{
    return ((4.0 / 3.0) * PI * pow(radius, 3));
}