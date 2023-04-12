/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

using namespace std;
#include <iostream>

bool isLeap(int year) {
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}
int main(void) {
for(int year = 1995; year < 2017; year++){
    cout << year << " -> " << isLeap(year) << endl;
}
return 0;
} 
