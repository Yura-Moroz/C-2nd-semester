/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int n = sizeof(vector) / sizeof(vector[0]);
    int* pointer = vector; 
    int max = *pointer; 
    pointer++; 
    for (int i = 1; i < n; i++) {
        if (*pointer > max) {
            max = *pointer; 
        }
        pointer++; 
    }
    cout << "Maximum element: " << max << endl;
    return 0;
}
