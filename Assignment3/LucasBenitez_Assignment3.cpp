// COP3014 - Assignment Number 3
// Purpose: Files practice. Random number generation practice.
// Author: Lucas Benitez, lbenitez2019@gmail.com
// Last edited: 9/25/2022


#include <iostream>                                       // Include standard library
#include <cstdlib>                                        // Include library
#include <ctime>                                          // Include library
#include <fstream>                                        // Include File Stream library
#include <cmath>                                          // Include library for math functions
using namespace std;



int main()                                                // Main function
{
    int lc = 0;                                           // loop control
    int N;                                                // declare variable for number of random numbers
    int rn;                                               // random number 
    int avg = 0;                                          // Running sum of rn's
    int avg2 = 0;                                         // Average for STD deviation loop
    double STD;                                           // square root of the average 2
    ifstream in_stream;                                   // in stream
    ofstream out_stream;                                  // out stream

    cout << "How many RN's: ";                            // Prompt for nuber of random numbers to be generated
    cin >> N;                                             // store

    if (N < 1 || N > 1000)                                // Check if N is less than or equal to 1000 and > 0
    {
        cout << "Invalid range. Enter a value 1-1000\n";
        exit(2);
    }

    out_stream.open("rn.txt");                            // Open file
    if (out_stream.fail())                                // Exit code if file fails to open
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }


    srand(time(0));                                       // Seed random number generation
    while (lc < N)
    {
        rn = rand() % 900 + 100;                          // Scale the number rand of randomly generated number  
        avg += rn;                                        // add last rn to running sum 
        cout << "Random number:" << rn << endl;           // Test print random number
        out_stream << rn << endl;                         // write rn to the file "rn.txt"



        lc++;                                             // Increment loop control
    }

    avg /= N;                                             // Calculate average
    cout << "the average the numbers is: " << avg << endl;
    out_stream << "number average: " << avg << endl;



    in_stream.open("rn.txt");                             // Open in stream
    if (in_stream.fail())                                 // Exit with 3 if in stream fails to open 
    {
        cout << "Input file opening failed.\n";
        exit(3);
    }

    lc = 0;                                               // reset loop control
    while (lc < N)
    {
        in_stream >> rn;
        cout << rn << endl;
        rn -= avg;
        avg2 += pow(rn, 2);
        cout << "running sum = " << avg2;


        /*
        rn = (rand() % 1000);                             // Scale the number rand of randomly generated number
        avg += rn;                                        // add last rn to running sum
        cout << "Random number:" << rn << endl;           // Test print random number
        out_stream << rn << endl;                         // write rn to the file "rn.txt"
        */


        lc++;                                             // Increment loop control
    }

    avg2 /= N;
    cout << endl << "the AVG is: " << avg2 << endl;
    STD = sqrt(avg2);
    cout << "the STD is: " << STD;
    out_stream << "the STD is: " << STD << endl;

    in_stream.close();                                    // close the READ  stream
    out_stream.close();                                   // close the WRITE stream

    return 0;                                             // Return 0
}


