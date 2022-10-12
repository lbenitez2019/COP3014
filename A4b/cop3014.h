#pragma once
// Definition for class cop3014

class cop3014
{
public:
	// -- Public functions --
	void prompt_for_scores();
	void display_report_card();
	bool validate_score(short score, short score_type);

	// Just for testing/debbugging
	void display_init_values();

	// Constructors
	cop3014();		// Default contructor, does nothing.

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

	// Specialty functions
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
	const short st_exam = 2;

	// Quiz/Test max scores
	const short qs_max = 10;	// Quiz Score max value 
	const short es_max = 100;	// Exam Score max value

	// Quiz/Test weight for final grade
	const double q1_w = .10;	// Quiz 1 weight for final grade
	const double q2_w = .10;	// Quiz 2 weight for final grade
	const double me_w = .30;	// Midterm Exam weight for final grade
	const double fe_w = .50;	// Final Exam weight for final grade

};
