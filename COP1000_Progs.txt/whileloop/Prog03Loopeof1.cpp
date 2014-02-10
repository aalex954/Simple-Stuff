// A sinle line comment.
/* This is
   Multiple lines comment. */

#include <iostream>
using namespace std;

#include <fstream>
#include <cstdlib>

int main ()
{
    // ifstream inFile("data1.dat", ios::in);
    ifstream inFile("data2.dat", ios::in);
    
    
    if (!inFile) {
       cerr << "File could not be opened" << endl;
       exit(1);
    } //endif
    
    // int tot, num, sum, avg;
    
    int num;
    double sum, avg;
    
    int count = 0;
    while (inFile >> num) {
          cout << "number in the file is : " << num << endl;
          sum = sum + num;
          count = count + 1;
    } //end of while
    
    avg = sum/count;  //CAUTION! May NOT produce correct result.
    cout << endl << "The average of numbers in the input file is:  "<< avg << endl << endl;
    
    system("PAUSE");
}
