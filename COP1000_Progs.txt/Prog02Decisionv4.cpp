// A sinle line comment.
/* This is
   Multiple lines comment. */

#include <iostream>
using namespace std;

int main ()
{
    int grade;
    // char gr_letter;
    
    cout << "Enter a Grade between 0 - 100  ";
    cin >> grade;
    
    if (grade >= 90) {
       
       cout << "Your Grade is A. Excellen Job!\n";
    } // end if
    else if (grade >= 80) {
       
       cout << "Your Grade is B. Good Job!\n";
    } // end if
    else if (grade >= 70) {
       
       cout << "Your Grade is C. Fair Job!\n";
    } // end if
    else if (grade >= 60) {
       
       cout << "Your Grade is D. \n";
    } // end if
    else {
       cout << "Your Grade is F. You did not pass the class! \n";
    } // end if
    
    system("PAUSE");
}
