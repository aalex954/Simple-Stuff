// A sinle line comment.
/* This is
   Multiple lines comment. */

#include <iostream>
using namespace std;

#include <fstream>
#include <cstdlib>

int main ()
{
    // ofstream outFile("data1.dat", ios::out);
    ofstream outFile("data2.dat", ios::out);
    
    if (!outFile) {
       cerr << "File could not be opened" << endl;
       exit(1);
    } //endif
    
    cout << "Enter an integer number " << endl
         << "Enter end-of-file <CTRL+Z> to end input.\n ? ";
         
    
    // int tot, num, sum, avg;
    
    int num;
    double sum, avg;
    
    while (cin >> num) {
          outFile << num << ' ' << endl;
          cout << " ? ";
    } //end of while
    
    system("PAUSE");
}
