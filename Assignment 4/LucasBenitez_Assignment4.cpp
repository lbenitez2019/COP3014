// Course     : COP3014
// Date       : 10/10/2022
// Purpose    : 

//  Class variable Requirments: 
//  REQ1: define a class called COP3014   !
//  REQ2: create member variables for 2 quizzes         !
//  REQ3: each quiz has a grade of 0-10 points      !
//  REQ4: create member variables for a midterm and final exam !
//  REQ5: The midterm and final score of 0-100 points       !
//  REQ6: create member variable for final grade                  !
//  REQ7: the final numeric grade is the wieghted average of quizzes and exams  !
//  REQ8: the weights are as follows: quizzes = 10% each, midterm = 30%, and final = 50%  !
//  REQ9: create member variable for student letter grade  !
//  REQ10: grades 90+ are an A, 80-89 is B, 70-79 is C, 60-69 is D, and 59 and below F !
//  REQ11: create a int member representing the Z number with exactly 8 digits    !

// Class function Requirments: 
//  REQ1: Must include getter and setter functions for all member variables !
//  REQ2: A void function to:   !
//         - calculate the weighted average !
//         - store the weighted average !
//  REQ3: A void function to: !
//         - map weighted average to a letter grade !
//         - store the letter grade !
//  REQ4: a function to print out the students report card (all information) !

#include <cstdlib>      // Always needed
#include <iostream>
using namespace std;


class cop3014 {

    public:
        void calc_avg_gr();                         //calculate and store the final weighted average
        void map_lett_gr();                         //map and store the final letter grade 
        void print_report_card();                   //print student report card 
        void prompt_for_info();                     //prompt user for scores and znumber

    private:
        int gr_q1;                                  //quiz 1 grade
        int gr_q2;                                  //quiz 2 grade
        int gr_me;                                  //midterm exam grade
        int gr_fe;                                  //final exam grade
        double gr_sgn;                              //final student course grade
        char gr_sgl;                                //final student letter grade
        long int znum;                              //student z number
        
        const int q_max=10;                         //quiz max grade
        const int e_max=100;                        //exam max grade
        const double w_q=.10;                       //quiz 1 and 2 weight
        const double w_m=.30;                       //midterm exam weight
        const double w_f=.30;                       //final exam weight

        const int grade_a = 90;                     //min grade for A
        const int grade_b = 80;                     //min grade for B
        const int grade_c = 70;                     //min grade for C
        const int grade_d = 60;                     //min grade for D
        const int grade_f = 59;                     //max grade for F

        int get_q1();                               //get quiz 1 grade
        int get_q2();                               //get quiz 2 grade
        int get_me();                               //get midterm exam grade
        int get_fe();                               //get final exam grade

        double get_sgn();                           //get final student number grade
        char get_sgl();                             //get final student letter grade
        long int get_znum();                        //get student znumber

        bool set_q1(int grade);                     //set quiz 1 grade
        bool set_q2(int grade);                     //set quiz 2 grade
        bool set_me(int grade);                     //set midterm exam grade
        bool set_fe(int grade);                     //set final exam grade
                                  
        bool set_sgn(double grade);                 //set final student number grade
        bool set_sgl(char grade);                   //set final student letter grade
        bool set_znum(long int z);                  //set student znumber
};

int main()
{
    cop3014 student1;
    // student1.prompt_for_info();
    return (0);                                     // exit normally (with error code 0)

}


int cop3014::get_q1()                               //get quiz 1 score 
{
    return gr_q1;
};     

int cop3014::get_q2()                               //get quiz 2 score  
{
    return gr_q2;
};     

int cop3014::get_me()                               //get midterm exam score  
{
    return gr_me;
};     

int cop3014::get_fe()                               //get final exam score  
{
    return gr_fe;
};                              


double cop3014::get_sgn()                           //get final number grade  
{
    return gr_sgn;
};                              


char cop3014::get_sgl()                             //get final letter grade
{
    return gr_sgl;
};                              


long int cop3014::get_znum()                        //get znumber
{
    return znum;
};                              




bool cop3014::set_q1(int grade)                     //set quiz 1 score 
{                
    gr_q1 = grade;
    return 1;
};                                                    
                                                      
bool cop3014::set_q2(int grade)                               //set quiz 2 score  
{            
    gr_q2 = grade;
    return 1;                                     
};                                                    
                                                      
bool cop3014::set_me(int grade)                               //set midterm exam score  
{                    

    gr_me = grade;                                     
    return 1;                                     
};                                                    
                                                      
bool cop3014::set_fe(int grade)                               //set final exam score  
{                                                     
    gr_fe = grade;                                     
    return 1;                                     
};                                                    
                                                      
                                                      
bool cop3014::set_sgn(double grade)                           //set final number grade  
{                                                     
    gr_sgn = grade;                                    
    return 1;                                    
};                                                    
                                                      
                                                      
bool cop3014::set_sgl(char grade)                             //set final letter grade
{            
    gr_sgl = grade;                                    
    return 1;                                    
};                                                    
                                                      
                                                  
bool cop3014::set_znum(long int z)                        //set znumber
{
    znum = z;
    return 1;
};                              

                        
//calculate and store the final weighted average 
void calc_avg_gr()
{

};


//map and store the final letter grade 
void map_lett_gr()
{

};

//print student report card 
void print_report_card() 
{

};
//prompt user for scores and znumber
void prompt_for_info() 
{

};

