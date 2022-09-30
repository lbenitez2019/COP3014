/*
COP3014: File Manipulations, reading to the end of the file
Instructor: Sareh Taebi
Taken from:  "Problem Solving with C++", Walter Savitch
Date: 09/27/2022
*/


#include <iostream>
#include <fstream>      //needed to include files
#include <cstdlib>
#include <iomanip>

using namespace std;


void make_neat(ifstream& messy_file, ofstream& neat_file, int number_after_decimalpoint, int field_width);
//Precondition: The streams messy_file and neat_file have been connected to files using the function open.
//Postcondition: The numbers in the file connected to messy_file have been written to the screen and to the file connected to the stream neat_file.
//The numbers are written one per line, in fixed-point notation (that is, not in e-notation), with number_after_decimalpoint digits after the decimal point;
//each number is preceded by a plus or minus sign and each number is in a field of width field_width. (This function does not close the file.)


int main()
{
    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("infile.txt");
    if (in_stream.fail( ))
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }
    out_stream.open("outfile.dat");
    if (out_stream.fail( ))
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }

    make_neat(in_stream, out_stream, 5, 12);     //function call

    in_stream.close( );
    out_stream.close( );

    return 0;
}


void make_neat(ifstream& messy_file, ofstream& neat_file, int number_after_decimalpoint, int field_width)
{
    neat_file.setf(ios::fixed);
    neat_file.setf(ios::showpoint);
    neat_file.setf(ios::showpos);
    neat_file.precision(number_after_decimalpoint);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.setf(ios::showpos);
    cout.precision(number_after_decimalpoint);

    double next;
    while (messy_file >> next)
    {
    cout << setw(field_width) << next << endl;
    neat_file << setw(field_width) << next << endl;
    }
}
