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
//          REQ4 - Test by generating multiple objects, and printing the student object’s record from COP3014.
//

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
		bool set_q1_score(short score);
		void set_q2_score(short score);
		void set_me_score(short score);
		void set_fe_score(short score);
		void set_fcg_n_score(double score);
		void set_fcg_l_score(char score);
		void set_znum(long int new_znumber);

		bool validate_score(short score, short score_type);

		short get_q1_score();
		short get_q2_score();
		short get_me_score();
		short get_fe_score();
		double get_fcg_n_score();
		char get_fcg_l_score();
		long int get_znum();
		double calc_f_grade_num();
		char calc_f_grade_lett();

	private:
		// Student info
		long int znumber;			// Student FAU Z-Number
				
		// Letter grade mapping to score
		const short grade_a = 90;
		const short grade_b = 80;
		const short grade_c = 70;
		const short grade_d = 60;
		const short grade_f = 59;

		// Score Types
		const short st_quiz = 1;
		const short st_test = 2;
		// 10+10 = 20
		// 100

		// Quiz/Test max scores
		const short qs_max = 10;	// Quiz Score max value 
		const short es_max = 100;	// Exam Score max value

		// Quiz/Test weight for final grade
		const double q1_w = .10;	// Quiz 1 weight for final grade
		const double q2_w = .10;	// Quiz 2 weight for final grade
		const double me_w = .30;	// Midterm Exam weight for final grade
		const double fe_w = .50;	// Final Exam weight for final grade

		// Variables to hold grades
		double gr_fcg_n;			// Final course grade, numeric/%
		char gr_fcg_l;				// Final grade, letter/alpha
		short gr_q1;				// Holds score for Quiz 1
		short gr_q2;				// Holds score for Quiz 2
		short gr_me;				// Holds score for Midterm Exam
		short gr_fe;				// Holds score for Final Exam

};



int main()
{
	char lc = 'y';  // Outer loop control
	while (lc == 'y' || lc == 'Y')
	{
		long int new_znumber;
		short new_score;

		cop3014 student1;

		cout << "Znumber: ";
		cin >> new_znumber;
		student1.set_znum(new_znumber);
		cout << "The Znumber is: " << student1.get_znum() << endl;

		cout << "Quiz 1 score: ";
		cin >> new_score;
		student1.set_q1_score(new_score);
		cout << "Q1 score: " << student1.get_q1_score() << endl;
		
		cout << "Quiz 2 score: ";
		cin >> new_score;
		student1.set_q2_score(new_score);
		cout << "Q2 score: " << student1.get_q2_score() << endl;
		
		cout << "Midterm Exam score: ";
		cin >> new_score;
		student1.set_me_score(new_score);
		cout << "Midterm score: " << student1.get_me_score() << endl;
		
		cout << "Final Exam score: ";
		cin >> new_score;
		student1.set_fe_score(new_score);
		cout << "Final score: " << student1.get_fe_score() << endl;

		cout << "FINAL Course Grade numeric: " << student1.calc_f_grade_num() << endl;
		
		cout << "FINAL Course Grade letter: " << student1.calc_f_grade_lett() << endl;
				

		cout << "Continue? (y/n) ";
		cin >> lc;
	}
	
	return 0;
}


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


double get_fcg_n_score();
char get_fcg_l_score();


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
	double grade=0;
	grade = gr_q1 + gr_q2 + gr_me*me_w + gr_fe*fe_w;
	set_fcg_n_score(grade);

	return grade;

};

char cop3014::calc_f_grade_lett()
{
	
	if (gr_fcg_n >= 90) {

		cout << "got an A" << endl;
		set_fcg_l_score('A');
		return 'A';
	}

	if (gr_fcg_n >= 80) {

		cout << "got a B" << endl;
		set_fcg_l_score('B');
		return 'B';
	}

	if(gr_fcg_n>=70){
		cout << "got a C" << endl;
		set_fcg_l_score('C');
		return 'C';
	}

	if(gr_fcg_n>=60){
		set_fcg_l_score('D');
		cout << "got a D" << endl;
		return 'D';
	}

	if (gr_fcg_n <= 59) {
		set_fcg_l_score('F');
		cout << "got an F" << endl;
		return 'F';
	}

}

bool cop3014::validate_score(short score, short score_type)
{
	bool output=0;

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

};