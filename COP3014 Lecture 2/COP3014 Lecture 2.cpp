/*
COP3014: Programmming II
Lecture 02: Data Types and Arithmetic (Reference: "Problem Solving with C++",
Walter Savitch)
Instructor: S. Taebi
*/
#include <iostream>
#include <string>     //needed for type string

using namespace std;

int main()
{
    //program I : practicing char
    char symbol1, symbol2, symbol3;
    int number = (1 / 3) * 3;
    double c = 20;
    double f;

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
    return 0;
}
