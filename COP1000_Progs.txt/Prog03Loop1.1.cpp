// A sinle line comment.
/* This is
   Multiple lines comment. */

#include <iostream>
using namespace std;

int main ()
{
    int num;
    double sum, avg;
    sum = 0;
    for (int i = 0; i < 5; i = i + 1) {
        cout << "Enter an integer number  ";
        cin >> num;
        sum = sum + num;
        // cout << "partial sum is:   " << sum;
    } // end for
    avg = sum/5;
    cout << " The average of numbers that you entered is:   "<< avg << endl;
             
    system("PAUSE");
}
