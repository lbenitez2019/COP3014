/*
COP3014: Using files for input and output of data
Reads three numbers from the file infile.dat, sums the number and writes the sum to the file outfile.dat.
Instructor: Sareh Taebi
Taken from:  "Problem Solving with C++", Walter Savitch
Date: 09/22/2022
*/

// Compiler directives
#include <iostream>
#include <fstream>      //needed to include files
#include <cstdlib>
using namespace std;


int main()
{
    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("infile.txt");
    if (in_stream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(3);
    }
    out_stream.open("outfile.dat");
    if (out_stream.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }
    int first, second, third;
    in_stream >> first >> second >> third;
    out_stream << "The sum of the first 3" << endl 
        << "numbers in infile.dat" << endl 
        << "is " << (first + second + third)
        << endl;
    in_stream.close();
    out_stream.close();

    return 0;
}
