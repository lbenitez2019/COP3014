// Course: COP3014
// Date : OCT-7-2022
// Assignment: 4
// Purpose: Prompt for student Z-num, scores for quizzes and exams, and print final Report Card
// Requirements: 
//	REQ1  - Define a class named "cop3014" 
//  REQ2  - cop3014 must have the following member VARIABLES:
//			1) Student Z-number  
//		 	2) Quiz1
//			3) Quiz2
//			4) Midterm Exam
//			5) Final Exam
//			6) Final Grade Avg %
//			7) Final Letter Grade
//	REQ3  - Quizzes have min score 0, max score of 10
//  REQ4  - Midterm and Final have min score 0, max score of 100
//  REQ5  - Final Grade weights: Quizzes 10% each, Midterm 30%, Final 50%
//  REQ6  - cop3014 must have a VOID FUNCTION to: 
//				- calculate numeric weighted average grade for the entire course (0% - 100%)  
//				- set the corresponding class variable w/ calculated number
//  REQ7  - cop3014 must have a VOID FUNCTION to 
//				- convert numeric average to a final letter grade
//				- set the corresponding class member variable w/ letter grade.  
//  REQ8  - cop3014 must have get/set functions for all class variables
//  REQ9  - cop3014 must have a function to display a Report Card: 
//				- z-number
//				- All Quiz/Exam scores and Final Grade to the screen.
//  REQ10 - Test by generating multiple objects, and printing the student object’s record from COP3014.
//


// Includes and other compiler directives
#include "../A4b/cop3014.h"
#include <iostream>
using namespace std;


int main()
{
	// Variable declarations
	cop3014 student1;

	char lc = 'y';  // Outer loop control
	while (lc == 'y' || lc == 'Y')
	{
		// DEBUG ONLY - Displays initial values of cop3014 variable members
		student1.display_init_values();

		// Prompt for and store Z-Number and test scores
		student1.prompt_for_scores();

		// Display Z-Number, quiz/test scores and final grade to screen
		student1.display_report_card();

		// Prompt user to continue or end
		cout << "Continue? (y/n) ";
		cin >> lc;
	}

	return 0;
}

