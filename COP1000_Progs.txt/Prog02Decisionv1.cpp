// A sinle line comment.
/* This is
   Multiple lines comment. */

#include <iostream>
using namespace std;

int main ()
{
    int num;
    
    cout << "Enter a positive number  ";
    cin >> num;
    if (num > 0) {
       // cout << "\n";
       cout << endl << num << "   is a Positive Number\n";
    } // end if
            
    system("PAUSE");
}
