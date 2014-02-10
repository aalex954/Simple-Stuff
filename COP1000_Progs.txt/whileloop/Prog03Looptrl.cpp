// A sinle line comment.
/* This is
   Multiple lines comment. */

#include <iostream>
using namespace std;

int main ()
{
    int num, sum;
    // double sum;
    double avg;
    sum = 0;
    
    cout << "Enter a number to compute and a NEGATIVE number to stop : ";
    cin >> num; // priming read
    
    int count = 0;
    
    while (num >= 0) {
        count = count + 1;
        // cout << "count is: " << count << endl;
        sum = sum + num;
        cout << "Enter a number to compute and a NEGATIVE number to stop : ";
        cin >> num; // loop read
        
        
        // cout << "partial sum is:   " << sum;
    } // end while
    if (count > 0){
    
      // avg = static_cast <double> (sum) / count;
       avg = sum / count;
       cout << " The average of numbers that you entered is:   "<< avg << endl;
    } // end if
   
             
    system("PAUSE");
}
