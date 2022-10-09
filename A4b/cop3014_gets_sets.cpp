// Implementation of functions for class cop3104


// Includes and other compiler directives
#include "../A4b/cop3014.h"
#include <iostream>

using namespace std;

// ----- Z Number -----
long int cop3014::get_znum()
{
	return znumber;
};

void cop3014::set_znum(long int new_znumber)
{
	znumber = new_znumber;
};

// ----- Quiz 1 score -----
bool cop3014::set_q1_score(short score)
{
	gr_q1 = score;
	return 1;
};

short cop3014::get_q1_score()
{
	return gr_q1;
};

// ----- Quiz 2 score -----
void cop3014::set_q2_score(short score)
{
	gr_q2 = score;

};

short cop3014::get_q2_score()
{
	return gr_q2;
};

// ----- Midterm Exam score -----
void cop3014::set_me_score(short score)
{
	gr_me = score;

};

short cop3014::get_me_score()
{
	return gr_me;
};

// ----- Final Exam score -----
void cop3014::set_fe_score(short score)
{
	gr_fe = score;

};

short cop3014::get_fe_score()
{
	return gr_fe;
};

// ----- Final Course Grade, numeric -----
void cop3014::set_fcg_n_score(double score)
{
	gr_fcg_n = score;

};

double cop3014::get_fcg_n_score()
{
	return gr_fcg_n;

};

// ----- Final Course Grade, letter grade -----
void cop3014::set_fcg_l_score(char score)
{
	gr_fcg_l = score;

};

char cop3014::get_fcg_l_score()
{
	return gr_fcg_l;

};
