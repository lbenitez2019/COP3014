// Course: COP3014
// Date : OCT-7-2022
// Assignment: 4
// Purpose: REQ1 - Define a class named "cop3014" 
//          REQ2 - cop3014 must have the following members
//          REQ2 - cop3014 must have get/set functions for all variables
//          REQ3 - cop3014 must have a function to calculates the weighted average numeric 
//				   score for the entire course and sets the corresponding member variable
//          REQ3 - cop3014 must have a function to calculate the final letter grade and 
//				   sets the corresponding member variable
//          REQ4 - cop3014 must have a function to display: z-number, and all grades to the screen.
//          REQ4 - 

#include <iostream>
using namespace std;

//*********************************************************************
// Class / Function prototypes for structures.
//*********************************************************************

// 
// 
class cop3014
{
	public:
		void set_q1_score(short score);
		void set_q2_score(short score);
		void set_me_score(short score);
		void set_fe_score(short score);
		void set_znum(short znumber);

		short get_q1_score();
		short get_q2_score();
		short get_me_score();
		short get_fe_score();
		short get_znum();

	private:
		// Student info
		short znumber;			// Student FAU Z-Number
				
		// Letter grade mapping to score
		const short grade_a = 90;
		const short grade_b = 80;
		const short grade_c = 70;
		const short grade_d = 60;
		const short grade_f = 59;

		// Quiz/Test max scores
		const short q1_max = 10;	// Quiz 1 max score
		const short q2_max = 10;	// Quiz 2 max score
		const short me_max = 100;	// Midterm Exam max score
		const short fe_max = 100;	// Final Exam max score

		// Quiz/Test weight for final grade
		const double q1_w = .10;	// Quiz 1 weight for final grade
		const double q2_w = .10;	// Quiz 2 weight for final grade
		const double me_w = .30;	// Midterm Exam weight for final grade
		const double fe_w = .50;	// Final Exam weight for final grade

		// Variables to hold grades
		double gr_course_n;			// Final course grade, numeric/%
		char gr_course_l;			// Final grade, letter/alpha
		short gr_q1;				// Holds score for Quiz 1
		short gr_q2;				// Holds score for Quiz 2
		short gr_me;				// Holds score for Midterm Exam
		short gr_fe;				// Holds score for Final Exam

};



int main()
{

	
	return 0;
}



void cop3014::set_q1_score(short score) {

	
};
