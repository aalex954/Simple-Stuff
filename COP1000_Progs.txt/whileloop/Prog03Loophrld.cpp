// A sinle line comment.
/* This is
   Multiple lines comment. */

#include <iostream>
using namespace std;

int main ()
{
   // int tot, num, sum, avg;
    
     int tot, num;
     double avg, sum;
    
    sum = 0;
    
    cout << "Enter a number to repeat the loop : ";
    cin >> tot;
    
    int count = tot;
    while (count > 0) {
        cout << "Enter an integer number  ";
        cin >> num;
        sum = sum + num;
        count = count - 1;
        
        // cout << "partial sum is:   " << sum;
    } // end while
    avg = sum/tot;
    cout << " The average of numbers that you entered is:   "<< avg << endl;
             
    system("PAUSE");
}
