// A sinle line comment.
/* This is
   Multiple lines comment. */

#include <iostream>
using namespace std;

int main ()
{
    // int tot, num, sum, avg;
    
    int tot, num;
    double sum, avg;
    
    sum = 0;
    cout << "Enter a number to repeat the loop : ";
    cin >> tot;
    for (int i = tot; i > 0; i = i - 1) {
        cout << "Enter an integer number  ";
        cin >> num;
        sum = sum + num;
        // cout << "partial sum is:   " << sum;
    } // end for
    
    avg = sum/tot;
    cout << " The average of numbers that you entered is:   "<< avg << endl;
             
    system("PAUSE");
}
