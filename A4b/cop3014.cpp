// Implementation of special functions for class cop3104


// Includes and other compiler directives
#include "../A4b/cop3014.h"
#include <iostream>
using namespace std;


//***********************************************************
// parent class	: cop3014
// funct. name	: cop3014() 
// purpose		: Default constructor
// inputs		: none
// outputs		: none
// remarks		: Does nothing
//***********************************************************
cop3014::cop3014()
{
	cout << "hello from default contructor" << endl;
};

//***********************************************************
// parent class	: cop3014
// funct. name	: cop3014()
// purpose		: Constructor
// inputs		: none
// outputs		: none
// remarks		: Does nothing
//***********************************************************
cop3014::cop3014(int init_pattern)
{
	cout << "hello from alternative contructor" << endl;
	gr_fcg_n = init_pattern; 		// Init numeric final course grade w. input
	gr_fcg_l = 'Y';					// Init letter final grade to "Y"
	gr_q1 = init_pattern;			// Init Quiz 1 w. input 
	gr_q2 = init_pattern;			// Init Quiz 2 w. input
	gr_me = init_pattern;			// Init Midterm Exam w. input
	gr_fe = init_pattern;			// Init Final Exam w. input

};


//***********************************************************
// parent class	: cop3014
// funct. name	: prompt_for_scores() 
// purpose		: a. prompts user for student Z-number and grades
//				: b. stores entered data to corr. variables
// inputs		: 'this'
// outputs		: none
// remarks		: Possible future improvements:
//				: a. validate values entered by user	
//				: b. provide success/failure bool as output	
//***********************************************************
void cop3014::prompt_for_scores()
{
	// Local Variable Declarations
	long int new_znumber=999999999; 
	short new_score=999;
	bool valid=0;

	// Prompt for and store Z-Number
	do 
	{
		cout << "Z-number (exactly 8 digits): ";
		cin >> new_znumber;
		valid = !cin.fail();	// validate that what cin read matches type of variable (to detect if alpha characters entered)
		set_znum(new_znumber);
		
		if (!valid)
		{
			cout << endl << "INVALID. Letters not allowed. Only 8 digits. Pls re-enter." << endl;
			cin.clear();
			cin.ignore(20,'\n');
		}
		
	} while (!valid);


	// Prompt for and store Quiz 1 Score
	do 
	{
		cout << "Quiz 1 score (0-10): ";
		cin >> new_score;
		set_q1_score(new_score);
		
		valid = validate_score(new_score, st_quiz);
		if (!valid)
			cout << endl << "INVALID. Only 0-10 allowed. Pls re-enter." << endl;

	} while (!valid);

	// Prompt for and store Quiz 2 Score
	do
	{
		cout << "Quiz 2 score (0-10): ";
		cin >> new_score;
		set_q2_score(new_score);

		valid = validate_score(new_score, st_quiz);
		if (!valid)
			cout << endl << "INVALID. Only 0-10 allowed. Pls re-enter." << endl;
	} while (!valid);

	// Prompt for and store Midterm Exam Score
	do
	{
		cout << "Midterm Exam score (0-100): ";
		cin >> new_score;
		set_me_score(new_score);

		valid = validate_score(new_score, st_exam);
		if (!valid)
			cout << endl << "INVALID. Only 0-100 allowed. Pls re-enter." << endl;
	} while (!valid);

	// Prompt for and store Final Exam Score
	do
	{
		cout << "Final Exam score (0-100): ";
		cin >> new_score;
		set_fe_score(new_score);

		valid = validate_score(new_score, st_exam);
		if (!valid)
			cout << endl << "INVALID. Only 0-100 allowed. Pls re-enter." << endl;
	} while (!valid);

};


//***********************************************************
// parent class	: cop3014
// funct. name	: display_init_values()
// purpose		: a. display initial values of variables
//				: b. FOR DEBUG ONLY
// inputs		: 'this'
// outputs		: none
// remarks		: 
//***********************************************************
void cop3014::display_init_values()
{
	// DEBUG ONLY - To get rid of compiler warnings
	cout << "--- TEST init values ---" << endl;
	cout << "Q1:" << get_q1_score() << " ";
	cout << "Q2:" << get_q2_score() << " ";
	cout << "ME:" << get_me_score() << " ";
	cout << "FE:" << get_fe_score() << " ";
	cout << "FG:" << get_fcg_n_score() << " ";
	cout << "FG:" << get_fcg_l_score() << endl;
	cout << "--- TEST init values ---" << endl << endl;
};


//***********************************************************
// parent class	: cop3014
// funct. name	: display_report_card()
// purpose		: a. Calc final numeric/letter grade for student
//				: b. Diaplays Report Card to stdout/console/screen
// inputs		: 'this'
// outputs		: none
// remarks		: Possible future improvements:
//				: a. handle errors from calculation of final grade	
//				: b. provide success/failure bool as output	
//***********************************************************
void cop3014::display_report_card()
{
	// Calculate final grade in numeric format and store to object
	set_fcg_n_score(calc_f_grade_num());

	// Store final letter grade to object
	set_fcg_l_score(calc_f_grade_lett());

	// Display Report Card
	cout << endl;
	cout << "------------------------------" << endl;
	cout << " Report Card for: Z-" << get_znum() << endl;
	cout << "------------------------------" << endl;
	cout << "Q1 score      : " << get_q1_score() << endl;
	cout << "Q2 score      : " << get_q2_score() << endl;
	cout << "Midterm test  : " << get_me_score() << endl;
	cout << "Final test    : " << get_fe_score() << endl;
	cout << "Final Grade   : " << get_fcg_n_score() << "% / " << get_fcg_l_score() << endl;
	cout << "------------------------------" << endl;
};


//***********************************************************
// parent class	: cop3014
// funct. name	: calc_f_grade_num()
// purpose		: Calc numeric weighted average final grade for student
// inputs		: 'this'
// outputs		: calculated numeric weighted average (type double)
// remarks		: Possible future improvements:
//				: a. handle errors from calculation of final grade	
//				: b. provide success/failure bool as output	
//***********************************************************
double cop3014::calc_f_grade_num()
{
	// Variable Declarations
	double grade = 0;

	// Calculate 
	grade = (double)gr_q1 + (double)gr_q2 + (double)gr_me * (double)me_w + (double)gr_fe * (double)fe_w;
	set_fcg_n_score(grade);

	// Safety check
	if (grade < 0 || grade > 100)
	{
		cout << endl << "ERROR in calculating weighted average!!" << endl;
		grade = 999;	// indicate error 
	}

	return grade;

};

//***********************************************************
// parent class	: cop3014
// funct. name	: calc_f_grade_lett()
// purpose		: Maps calculated numeric final grade to letter grade
// inputs		: 'this'
// outputs		: letter grade A/B/C/D/F or X for error (type char)
// remarks		: 
//***********************************************************
char cop3014::calc_f_grade_lett()
{

	if (gr_fcg_n < 0 || gr_fcg_n > 100)
	{
	// Indicate invalid grade
	cout << endl << "ERROR in mapping numeric grade to letter grade!!" << endl;
	return 'X'; 
	}

	if (gr_fcg_n >= grade_a)
	{
		set_fcg_l_score('A');
		return 'A';
	}

	if (gr_fcg_n >= grade_b)
	{
		set_fcg_l_score('B');
		return 'B';
	}

	if (gr_fcg_n >= grade_c)
	{
		set_fcg_l_score('C');
		return 'C';
	}

	if (gr_fcg_n >= grade_d)
	{
		set_fcg_l_score('D');
		return 'D';
	}

	if (gr_fcg_n <= grade_f)
	{
		set_fcg_l_score('F');
		return 'F';
	}

	// If we got here, something's wrong	
	cout << endl << "ERROR in mapping numeric grade to letter grade!!" << endl;
	return 'X'; 

}

//***********************************************************
// parent class	: cop3014
// funct. name	: validate_score()
// purpose		: validates quiz and exam scores
// inputs		: Score number, and score type (quiz or exam)
// outputs		: validates that score is valid for given score type
// remarks		: 
//***********************************************************
bool cop3014::validate_score(short score, short score_type)
{
	// Validate lower boundary
	if (score < 0)
		return 0; // invalid score. score must be > 0. 

	// Validate upper boundary
	if (score_type == st_quiz)
	{
		if (score <= qs_max)
			return 1;			// valid
	}
	else if (score_type == st_exam)
	{
		if (score <= es_max)
			return 1;			// valid
	}
	return 0; // indicate invalid
};