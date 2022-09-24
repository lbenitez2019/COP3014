// Course: COP3014
// Date : 9/24/2022
// Purpose: REQ1  - Generate a single random number "N" where (100 < N < 1000)
//          REQ2a - Generate "n" other random numbers
//          REQ2b - Store "n" random numbers in a file "rn.dat"
//          REQ3a - Display the average of the random numbers in "rn.dat" to screen
//          REQ3b - Store the average of the random numbers at the end of file "rn.dat"
//          REQ4a - Display the Std. Dev. of the random numbers in "rn.dat" to screen
//          REQ4b - Store the Std. Dev. of the random numbers at the end of "rn.dat"
//          


#include <iostream>
#include <fstream>      //needed to include files
#include <cstdlib>
#include <ctime>
#include <iomanip>


int main()
{
    using namespace std;
    
    // -- VARIABLE DECLARATIONS --
    
    ofstream out_stream;    // Stream for writing random numbers, and their average, into file rn.txt
    ifstream in_stream;     // Stream for reading random numbers from file rn.txt to calculate Std Deviation 
    int r;                  // To holds one random number
    int n = 0;              // Number "n" of random numbers ( 1 < n < 1000) 
    int lc;                 // Loop control 
    double avg=0.0;         // To calculate average of random numbers
    double a;               // To store the calculated average of random numbers
    double std=0.0;         // To calculate Std Deviation (STDEV)
    int std_n;              // To store random numbers READ from a file 

    // --------------------------------
    // -- PART 1: RANDOM NUMBERS     --
    // --------------------------------
    
    // Open WRITE stream to file rn.dat
    out_stream.open("rn.dat");      // open the stream / file for WRITING
    if (out_stream.fail())  
    {
        cout << "Could not open file rn.dat." << endl;
        exit(3);                    // Indicate error code 3
    }

    // Prompt user for number of random numbers
    // Validate:  0 < n < 1000
    cout << "No. of random #'s to generate? (1..999): ";
    cin >> n;
    if (n > 0 && n < 1000)
    {
        lc = n;                     // Set loop control to selected number
    }
    else
    {
        cout << "Selected number out of range (1..999)" << endl;
        exit(7);                     // Indicate error 7
    }

    // Generate the n random numbers, and write to stream / file
    srand(time(0));                 // Seed the rand() funtion with the current time
    
    while (lc > 0)                  // Counting down
    {
        r = rand() % 1000;          // Generate random number between 0 and 1000
        out_stream << r << endl;    // Write rn to file, and a new line / carriage return
        avg += r;                   // running sum of rn's

        cout << "Random number is: " << r;          // DELETE LATER - TEST ONLY Print rn to screen 
        cout << "  Running sum: " << avg << endl;   // DELETE LATER - TEST ONLY Print running sum of rn's to screen 
        
        lc--;                       // Decrement loop control
    }
    
    // Calculate the average of all random numbers, write to end of stream / file
    avg /= n;                                       // calculate average of all the rn's
    out_stream << endl << "  AVG of above " << n << " random numbers : " << avg << endl;   // write avg of rn's to file
    
    cout << "Average: " << avg << endl;             // Print average of all rn's to screen 
    
    // --------------------------------
    // -- PART 2: STANDARD DEVIATION --
    // --------------------------------
    
    // Open READ stream to file rn.dat
    in_stream.open("rn.dat");       // Open the same file/stream from PART 1, but for READING this time
    if (in_stream.fail())
    {
        cout << "Could not open file rn.dat." << endl;
        exit(5);                    // Indicate error code 5
    }

    // Prepare variables for READ loop 
    a = avg;                        // Store average of random numbers, from PART 1.  This is the "A" in the STD formula
    avg = 0;                        // reset average to zero before using it for STDEV calculation
    lc = n;                         // reset loop counter to original "n"

    while (lc > 0)
    {
        in_stream >> std_n;         // read item from file
        avg += pow((std_n - a), 2); // running sum for average for STDEV calc

        cout << "std_n " << lc << " is: " << std_n << endl; // DELETE LATER - TEST ONLY Print the rn that was just read from file. 

        lc--;                       // Decrement loop control counter
    }

    avg /= n;                       // calculate the average of all (n-A)^2

    cout << " The STDEV is: " << sqrt(avg) << endl; // Print STDEV to the screen
    
    out_stream << "STDEV of above " << n << " random numbers: " << sqrt(avg) << endl;     // Write STDEV to the file.

    in_stream.close();              // close the READ  stream
    out_stream.close();             // close the WRITE stream

    return (0);                     // exit normally (with error code 0)

}