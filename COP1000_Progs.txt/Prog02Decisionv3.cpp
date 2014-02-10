// A sinle line comment.
/* This is
   Multiple lines comment. */

#include <iostream>
using namespace std;

int main ()
{
    int num1, num2, num3, num4, small;
    
    cout << "Enter FOUR integer numbers  ";
    cin >> num1 >> num2 >> num3 >> num4;
    small = num1;
    if (num2 < small) {
       
       small = num2;
    } // end if
    if (num3 < small) {
       
       small = num3;
    } // end if
    if (num4 < small) {
       
       small = num4;
    } // end if
    
    cout << "The smallest number among four integers entered is: " << small << endl;
    system("PAUSE");
}
