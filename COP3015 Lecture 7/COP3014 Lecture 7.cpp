/*
COP3014: Program to demonstrate call-by-reference parameters
Date: 09/20/2022
Taken from : "Problem Solving with C++", by Walter Savitch
*/


#include <iostream>
using namespace std;


//Reads two integers from the keyboard.
void get_numbers(int& input1, int& input2);

//Interchanges the values of variable1 and variable2.
void swap_values(int& variable1, int& variable2);

//Shows the values of variable1 and variable2, in that order.
void show_results(int output1, int output2);

//Orders the numbers in the variables n1 and n2
//so that after the function call n1 <= n2.
void order(int& n1, int& n2);

//Outputs the values in output1 and output2.
//Assumes that output1 <= output2
void give_results(int output1, int output2);


int main()
{
    int first_num = 0, second_num = 0;


    ///////////////////////////////////First: Use this set of function calls to change the order of values ALL THE TIME
    get_numbers(first_num, second_num);
    swap_values(first_num, second_num);
    show_results(first_num, second_num);

    //////////////////////////////////Next: Use this set of function calls to change the order of values Only to achieve first_num < second_num
    get_numbers(first_num, second_num);
    order(first_num, second_num);
    give_results(first_num, second_num);



    return 0;
}

//function that reads inputs
void get_numbers(int& input1, int& input2)
{
    cout << "Enter two integers: ";
    cin >> input1
        >> input2;
}

//function that swaps two values in memory
void swap_values(int& variable1, int& variable2)
{
    int temp;
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

//function that displays the values
void show_results(int output1, int output2)
{
    cout << "In reverse order the numbers are: "
        << output1 << " " << output2 << endl;
}

//functions calling functions! Ensure that always n1 <= n2
void order(int& n1, int& n2)
{
    if (n1 > n2)
        swap_values(n1, n2);
}

//function to show results in increasing order
void give_results(int output1, int output2)
{

    cout << "In increasing order the numbers are: "
        << output1 << " " << output2 << endl;
}
