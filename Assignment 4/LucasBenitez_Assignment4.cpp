// Course     : COP3014
// Author     : Lucas Benitez
// Date       : OCT-9-2022
// Assignment : 4
// Purpose    : Implement a c++ class to collect/store grades and print a report card to screen.
// 
// Requirments: 
//  Class variable Requirments: 
//  !  REQ01: define a class called COP3014
//  !  REQ02: must have member variables for 2 quizzes
//  !  REQ03: each quiz has a grade of 0-10 points
//  !  REQ04: must have member variables for a midterm and final exam
//  !  REQ05: the midterm and final score of 0-100 points
//  !  REQ06: must have member variable for final grade
//  !  REQ07: final numeric grade is the wieghted average of quizzes and exams
//  !  REQ08: weights for final grade: quizzes = 10% each, midterm = 30%, and final = 50%
//  !  REQ09: must have member variable for student letter grade
//  !  REQ10: grades 90+ are an A, 80-89 is B, 70-79 is C, 60-69 is D, and 59 and below F
//  !  REQ11: create a int member representing the Z number with exactly 8 digits  
//
//  Class function Requirments: 
//  !  REQ12: must include getter and setter functions for all class member variables
//     REQ13: a void function to:
//            - calculate the weighted average final grade
//            - store the weighted average final grade
//     REQ14: a void function to:
//            - map weighted average to a letter grade
//            - store the letter grade
//     REQ15: a function to print out the students report card (all information)



//*************************************************************************************
// 
//*************************************************************************************
#include <cstdlib>                                  // Always needed
using namespace std;


//*************************************************************************************
// 
//*************************************************************************************
class cop3014 {

    public:
        void calc_avg_gr();                         // calc/store final weighted avg grade
        void map_lett_gr();                         // map avg to final letter grade and store  
        void print_report_card();                   // print student report card 
        void prompt_for_info();                     // prompt user for scores and znumber

    private:
        int gr_q1=999;                              // quiz 1 grade
        int gr_q2=999;                              // quiz 2 grade
        int gr_me=999;                              // midterm exam grade
        int gr_fe=999;                              // final exam grade
        double gr_sgn=999;                          // final student course grade
        char gr_sgl='x';                            // final student letter grade
        long int znum=99999999;                     // student z number
       
        const int q_max=10;                         // quiz max grade
        const int e_max=100;                        // exam max grade
        const double w_q=.10;                       // quiz 1 and 2 weight
        const double w_m=.30;                       // midterm exam weight
        const double w_f=.30;                       // final exam weight
        const int grade_a = 90;                     // min grade for A
        const int grade_b = 80;                     // min grade for B
        const int grade_c = 70;                     // min grade for C
        const int grade_d = 60;                     // min grade for D
        const int grade_f = 59;                     // max grade for F

        int get_q1();                               // get quiz 1 grade
        int get_q2();                               // get quiz 2 grade
        int get_me();                               // get midterm exam grade
        int get_fe();                               // get final exam grade
        double get_sgn();                           // get student final numberic grade
        char get_sgl();                             // get student final letter grade
        long int get_znum();                        // get student znumber
        
        bool set_q1(int grade);                     // set quiz 1 grade
        bool set_q2(int grade);                     // set quiz 2 grade
        bool set_me(int grade);                     // set midterm exam grade
        bool set_fe(int grade);                     // set final exam grade
        bool set_sgn(double grade);                 // set final student number grade
        bool set_sgl(char grade);                   // set final student letter grade
        bool set_znum(long int z);                  // set student znumber
};

//*************************************************************************************
// main
//*************************************************************************************
int main()
{
    cop3014 student1;
    student1.prompt_for_info();
    return (0);                                     // exit normally (with error code 0)

}

//*************************************************************************************
// cop3014 getter functions
//*************************************************************************************

//get quiz 1 score 
int cop3014::get_q1()                               
{
    return gr_q1;
};     

//get quiz 2 score  
int cop3014::get_q2()                               
{
    return gr_q2;
};     

//get midterm exam score  
int cop3014::get_me()                               
{
    return gr_me;
};     

//get final exam score  
int cop3014::get_fe()                               
{
    return gr_fe;
};                              

//get final number grade  
double cop3014::get_sgn()                           
{
    return gr_sgn;
};                              

//get final letter grade
char cop3014::get_sgl()                             
{
    return gr_sgl;
};                              

//get znumber
long int cop3014::get_znum()                        
{
    return znum;
};                              


//*************************************************************************************
// cop3014 setter functions
//*************************************************************************************

//set quiz 1 score 
bool cop3014::set_q1(int grade)                     
{                
    gr_q1 = grade;
    return 1;
};                                                    
                                                      
//set quiz 2 score  
bool cop3014::set_q2(int grade)                               
{            
    gr_q2 = grade;
    return 1;                                     
};                                                    
                                                      
//set midterm exam score  
bool cop3014::set_me(int grade)                               
{                    

    gr_me = grade;                                     
    return 1;                                     
};                                                    
                                                      
//set final exam score  
bool cop3014::set_fe(int grade)                               
{                                                     
    gr_fe = grade;                                     
    return 1;                                     
};                                                    
                                                      
//set final number grade  
bool cop3014::set_sgn(double grade)                           
{                                                     
    gr_sgn = grade;                                    
    return 1;                                    
};                                                    
                                                      
                                                      
//set final letter grade
bool cop3014::set_sgl(char grade)                             
{            
    gr_sgl = grade;                                    
    return 1;                                    
};                                                    
                                                      
//set znumber
bool cop3014::set_znum(long int z)                        
{
    znum = z;
    return 1;
};                              

                        
//*************************************************************************************
// cop3014 general functions
//*************************************************************************************

//calculate and store the final weighted average 
void cop3014::calc_avg_gr()
{

};

//map and store the final letter grade 
void cop3014::map_lett_gr()
{

};

//print student report card 
void cop3014::print_report_card()
{

};
//prompt user for scores and znumber
void cop3014::prompt_for_info()
{

};
