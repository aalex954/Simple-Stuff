// A sinle line comment.
/* This is
   Multiple lines comment. */

#include <iostream>
using namespace std;

int main ()
{
    // int num, sum, avg;
    
    
    int num;
    double avg, sum;
    sum = 0;
   
    int count = 5;
    while (count > 0) {
        cout << "Enter an integer number  ";
        cin >> num;
        sum = sum + num;
        count = count - 1;
        
        // cout << "partial sum is:   " << sum;
    } // end while
    avg = sum/5;   //CAUTION! May NOT produce correct result.
    cout << " The average of numbers that you entered is:   "<< avg << endl;
             
    system("PAUSE");
}
