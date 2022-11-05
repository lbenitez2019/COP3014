#include <iostream>
#include <iomanip>
using namespace std;
class COP3014
{
public:
    void input();
    void output();
    /* input & output functions */

    void set_record(int new_znumber, int new_quiz1, int new_quiz2, int
        new_midterm, int new_final);
    /* sets the variables for all grades */
    int get_quiz1();
    int get_quiz2();
    int get_midterm();
    int get_final();
    double get_avg();
    char get_letterGrade();
    /* returns the grade from the record */

private:
    void check_record();
    /* checks that znumber & all grades are valid inputs */
    void compute_average(double new_avg);
    /* computes class grade average */
    void compute_letterGrade(char letterGrade);
    /* computes class letter grade */

    /* private member variables */
    double avg;
    int znumber, quiz1, quiz2, midterm, final;
    char letterGrade;
};
int main()
{
    int choice;
    do
    {
        cout << endl
            << "Choose 1 if you want enter a students grades. \n"
            << "Choose 2 to exit this program. \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            COP3014 student1, student2, student3, student4, student5,
                student6, student7, student8, student9;
            student1.input();
            student2.set_record(64739463, 8, 7, 89, 79);
            student3.set_record(14563356, 3, 5, 68, 76);
            student4.set_record(43767624, 9, 0, 93, 87);
            student5.set_record(25326892, 5, 6, 53, 58);
            student6.set_record(65785242, 6, 7, 62, 69);
            student7.set_record(42678462, 2, 2, 37, 27);
            student8.set_record(72672673, 9, 9, 93, 97);
            student9.set_record(25468432, 7, 7, 76, 73);
            cout << "\nThe class records are as follows " << endl;
            cout << "| ZNumber |" << setw(12) << "| Quiz 1 |" <<
                setw(12) << "| Quiz 2 |" << setw(12)
                << "| Midterm |" << setw(10) << "| Final |" << setw(12) <<
                "| Average |" << setw(10) << "| Grade |" << endl;
            student1.output();
            student2.output();
            student3.output();
            student4.output();
            student5.output();
            student6.output();
            student7.output();
            student8.output();
            student9.output();
            break;
        }
    } while (choice != 2);
    return 0;
}
/* function definitions */
void COP3014::input()
{
    cout << "Enter the student ZNumber as a eight digit number: ";
    cin >> znumber;
    cout << "Enter the first quiz grade as a number 0-10: ";
    cin >> quiz1;
    cout << "Enter the second quiz grade as a number 0-10: ";
    cin >> quiz2;
    cout << "Enter the midterm grade as a number 0-100: ";
    cin >> midterm;
    cout << "Enter the final grade as a number 0-100: ";
    cin >> final;
    check_record();
    compute_average(0);
    compute_letterGrade(' ');
}
void COP3014::set_record(int new_znumber, int new_quiz1, int new_quiz2, int
    new_midterm, int new_final)
{
    znumber = new_znumber;
    quiz1 = new_quiz1;
    quiz2 = new_quiz2;
    midterm = new_midterm;
    final = new_final;
    check_record();
    compute_average(0);
    compute_letterGrade(' ');
}
void COP3014::output()
{
    cout << " Z" << znumber << ": " << setw(7) << get_quiz1() << setw(12) <<
        get_quiz2() << setw(12)
        << get_midterm() << setw(11) << get_final() << setw(11) << get_avg() <<
        setw(10) << get_letterGrade() << endl;
}
void COP3014::compute_average(double new_avg)
{
    new_avg = ((quiz1 * 10 + quiz2 * 10) / 2 * .2) + (midterm * .3) + (final
        * .5);
    avg = new_avg;
}
void COP3014::compute_letterGrade(char new_letterGrade)
{
    if ((avg <= 100) && (avg >= 90))
    {
        new_letterGrade = 'A';
        letterGrade = new_letterGrade;
    }
    else if ((avg <= 89) && (avg >= 80))
    {
        new_letterGrade = 'B';
        letterGrade = new_letterGrade;
    }
    else if ((avg <= 79) && (avg >= 70))
    {
        new_letterGrade = 'C';
        letterGrade = new_letterGrade;
    }
    else if ((avg <= 69) && (avg >= 60))
    {
        new_letterGrade = 'D';
        letterGrade = new_letterGrade;
    }
    else
    {
        new_letterGrade = 'F';
        letterGrade = new_letterGrade;
    }
}
void COP3014::check_record()
{
    if ((znumber < 10000000) || (znumber > 99999999) || (quiz1 < 0) || (quiz1 > 10) ||
        (quiz2 < 0) || (quiz2 > 10) || (midterm < 0) || (midterm > 100) || (final < 0) ||
        (final > 100))
    {
        cout << "Illegal record information. Aborting program.\n";
        exit(1);
    }
}
int COP3014::get_quiz1()
{
    return quiz1;
}
int COP3014::get_quiz2()
{
    return quiz2;
}
int COP3014::get_midterm()
{
    return midterm;
}
int COP3014::get_final()
{
    return final;
}
double COP3014::get_avg()
{
    return avg;
}
char COP3014::get_letterGrade()
{
    return letterGrade;
}
