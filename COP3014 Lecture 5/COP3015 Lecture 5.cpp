/*
COP3014
Lecture 05: loops
Author: Sareh Taebi
*/
#include <iostream>
using namespace std;
int main()
{
    ////////////////////////////////////////////////geetings   do while
    char ans;
    do
    {
        cout << "Hello\n";
        cout << "Do you want another greeting?\n"
            << "Press y for yes, n for no,\n"
            << "and then press return: ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');
    cout << "move on!\n\n";
    ///////////////////////////////////////////////////////////////
    /////////////////////////////////////debt on credit card  while
    double balance = 0.00;
    const double MINTEREST = 0.02;
    int month = 0;
    cout << "What's the balance on your credit card? ";
    cin >> balance;
    cout << "when will you pay it off? How many month later? ";
    cin >> month;
    int count = 0;
    cout << "This program tells you the amount\n"
        << "to accumulate a debt, starting with\n"
        << "The interest rate is" << MINTEREST << " per month.\n";
    while (count < month)
    {
        balance = balance + MINTEREST * balance;
        count++;
    }
    cout << "After " << count << " months,\n";
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "your balance due will be $" << balance << endl;
    ///////////////////////////////////////////////////////////////
    //////////////////////  calories consumed in a day   while with increment operator
    int number_of_items, count2, calories_for_item, total_calories;
    cout << "How many items did you eat today? ";
    cin >> number_of_items;
    total_calories = 0;
    count2 = 1;
    cout << "Enter the number of calories in each of the\n"
        << number_of_items << " items eaten:\n";
    while (count2++ <= number_of_items)
    {
        cin >> calories_for_item;
        total_calories = total_calories + calories_for_item;
    }
    cout << "Total calories eaten today = "
        << total_calories << endl;
    ///////////////////////////////////////////////////////////////
    ///////////////////////////////for loop demonstration to calculate sum of values
    int sum = 0;
    for (int n = 1; n <= 10; n++)
    {
        sum += n;
        cout << endl;
        cout << n << " :getting there\n";
    }
    cout << "The sum of the numbers 1 to 10 is " << sum << endl;
    return 0;
}
