// Course: COP3014
// Date : OCT-7-2022
// Assignment: 4
// Purpose:
// Requirements: 
//	REQ1  - Define a class named "cop3014" 
//  REQ2  - cop3014 must have the following member VARIABLES:
//			Student Z-number  
//		 	Quiz1
//			Quiz2
//			Midterm Exam
//			Final Exam
//			Final Grade Avg %
//			Final Letter Grade
//	REQ3  - Quizzes have max score of 10
//  REQ4  - Midterm and Final have max score of 100
//  REQ5  - Final grade weights: Quizzes 10% each, Midterm 30%, Final 50%
//  REQ6  - cop3014 must have a VOID FUNCTION to: 
//				- calculate weighted numeric average score for the entire course  
//				- sets the corresponding member variable.  
//  REQ7  - cop3014 must have a VOID FUNCTION to 
//				- convert numeric average to a final letter grade
//				- sets the corresponding member variable .  
//  REQ8  - cop3014 must have get/set functions for all variables
//  REQ9  - cop3014 must have a function to display: 
//				- z-number
//				- All Quiz/Exam scores and Final Grade to the screen.
//  REQ10 - Test by generating multiple objects, and printing the student object’s record from COP3014.
//


// Includes and other compiler directives
#include <iostream>
using namespace std;


// Class Definitions, function prototypes

class cop3014
{
	public:
		// -- Public functions --
		void prompt_for_scores();
		void display_report_card();
		bool validate_score(short score, short score_type);

		// Just for testing/debbugging
		void display_init_values();

	private: 
		// -- Private functions --

		// setter functions
		void set_znum(long int new_znumber);
		bool set_q1_score(short score);
		void set_q2_score(short score);
		void set_me_score(short score);
		void set_fe_score(short score);
		void set_fcg_n_score(double score);
		void set_fcg_l_score(char score);

		// getter functions
		long int get_znum();
		short get_q1_score();
		short get_q2_score();
		short get_me_score();
		short get_fe_score();
		double get_fcg_n_score();
		char get_fcg_l_score();

		// Other/Special functions
		char calc_f_grade_lett();
		double calc_f_grade_num();
		
		
		// -- Private variables  --
		
		// Student info
		long int znumber = 99999999; // Student FAU Z-Number
				
		// Variables to hold grades (init values are 'special' for debug)
		double gr_fcg_n = 999; 		// Final course grade, numeric/%
		char gr_fcg_l = 'X';		// Final grade, letter/alpha
		short gr_q1 = 999;			// Holds score for Quiz 1
		short gr_q2 = 999;			// Holds score for Quiz 2
		short gr_me = 999;			// Holds score for Midterm Exam
		short gr_fe = 999;			// Holds score for Final Exam

		// -- Private constants --
		
		// Letter grade mapping to score
		const short grade_a = 90;
		const short grade_b = 80;
		const short grade_c = 70;
		const short grade_d = 60;
		const short grade_f = 59;

		// Score Types
		const short st_quiz = 1;
		const short st_test = 2;

		// Quiz/Test max scores
		const short qs_max = 10;	// Quiz Score max value 
		const short es_max = 100;	// Exam Score max value

		// Quiz/Test weight for final grade
		const double q1_w = .10;	// Quiz 1 weight for final grade
		const double q2_w = .10;	// Quiz 2 weight for final grade
		const double me_w = .30;	// Midterm Exam weight for final grade
		const double fe_w = .50;	// Final Exam weight for final grade

};



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

void cop3014::prompt_for_scores()
{
	// Variable Declarations
	long int new_znumber;
	short new_score;

	// Prompt for and store Z-Number
	cout << "Znumber (exactly 8 digits): ";
	cin >> new_znumber;
	set_znum(new_znumber);

	// Prompt for and store Quiz 1 Score
	cout << "Quiz 1 score (0-10): ";
	cin >> new_score;
	set_q1_score(new_score);

	// Prompt for and store Quiz 2 Score
	cout << "Quiz 2 score (0-10): ";
	cin >> new_score;
	set_q2_score(new_score);

	// Prompt for and store Midterm Exam Score
	cout << "Midterm Exam score (0-100): ";
	cin >> new_score;
	set_me_score(new_score);

	// Prompt for and store Final Exam Score
	cout << "Final Exam score (0-100): ";
	cin >> new_score;
	set_fe_score(new_score);
};

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

void cop3014::display_report_card()
{
	// Calculate final grade in numeric format and store to object
	set_fcg_n_score(calc_f_grade_num());
	
	// Store final letter grade to object
	set_fcg_l_score(calc_f_grade_lett());

	// Display Report Card
	cout << endl;
	cout << "---------------------------" << endl;
	cout << "Z Number      : Z-" << get_znum() << endl;
	cout << "Q1 score      : " << get_q1_score() << endl;
	cout << "Q2 score      : " << get_q2_score() << endl;
	cout << "Midterm test  : " << get_me_score() << endl;
	cout << "Final test    : " << get_fe_score() << endl;
	cout << "Final Grade   : " << get_fcg_n_score() << " / " << get_fcg_l_score() << endl;
	cout << "---------------------------" << endl;
};

long int cop3014::get_znum()
{
	return znumber;
};

void cop3014::set_znum(long int new_znumber)
{
	znumber = new_znumber;
};

bool cop3014::set_q1_score(short score) 
{
	gr_q1 = score;
	return 1;
};

short cop3014::get_q1_score() 
{
	return gr_q1;
};

void cop3014::set_q2_score(short score) 
{
	gr_q2 = score;
	
};

short cop3014::get_q2_score() 
{
	return gr_q2;
};

void cop3014::set_me_score(short score) 
{
	gr_me = score;
	
};

short cop3014::get_me_score() 
{
	return gr_me;
};

void cop3014::set_fe_score(short score) 
{
	gr_fe = score;
	
};

short cop3014::get_fe_score() 
{
	return gr_fe;
};

void cop3014::set_fcg_n_score(double score) 
{
	gr_fcg_n = score;
	
};

double cop3014::get_fcg_n_score() 
{
	return gr_fcg_n;
	
};

void cop3014::set_fcg_l_score(char score) 
{
	gr_fcg_l = score;
	
};

char cop3014::get_fcg_l_score() 
{
	return gr_fcg_l;
	
};

double cop3014::calc_f_grade_num()
{
	// Variable Declarations
	double grade=0;

	// Calculate 
	grade = (double) gr_q1 + (double) gr_q2 + (double) gr_me * (double) me_w + (double) gr_fe * (double) fe_w;
	set_fcg_n_score(grade);

	return grade;

};

char cop3014::calc_f_grade_lett()
{
	
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

	if(gr_fcg_n >= grade_d)
		{
		set_fcg_l_score('D');
		return 'D';
		}

	if (gr_fcg_n <= grade_f) 
		{
		set_fcg_l_score('F');
		return 'F';
		}

	return 'X'; // Indicate invalid grade

}

bool cop3014::validate_score(short score, short score_type)
{
	if (score < 0)
		return 0; // invalid score. score must be > 0. 

	if (score_type == st_quiz)
	{
		if (score <= qs_max)
			return 1;			// valid
	}
	else if ( score_type == st_test)
	{
		if (score <= es_max)
			return 1;			// valid
	}
	return 0; // indicate invalid
};