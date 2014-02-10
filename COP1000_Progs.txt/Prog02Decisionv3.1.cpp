// A sinle line comment.
/* This is
   Multiple lines comment. */

#include <iostream>
using namespace std;

int main ()
{
    int num1, num2, num3, num4, large;
    
    cout << "Enter FOUR integer numbers  ";
    cin >> num1 >> num2 >> num3 >> num4;
    large = num1;
    if (num2 > large) {
       
       large = num2;
    } // end if
    if (num3 > large) {
       
       large = num3;
    } // end if
    if (num4 > large) {
       
       large = num4;
    } // end if
    
    cout << "The largest number among four integers entered is: " << large << endl;
    system("PAUSE");
}
