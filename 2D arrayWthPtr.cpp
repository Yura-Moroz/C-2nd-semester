/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib> // Для функції rand()
#include <ctime>   

using namespace std;

int main() {
    const int N = 5; 
    int arr[N][N];   

    srand(time(NULL)); 
    int* ptr = &arr[0][0];
    for (int i = 0; i < N * N; i++) {
        *ptr = rand() % 21 - 10; // Випадкове ціле число в діапазоні [-10, 10]
        ptr++;                   
    }

    cout << "Елементи на головній діагоналі:\n";
    ptr = &arr[0][0];
    for (int i = 0; i < N; i++) {
        cout << *ptr << " ";
        ptr += N + 1; 
    }
    cout << endl;

    cout << "Елементи на побічній діагоналі:\n";
    ptr = &arr[0][N - 1];
    for (int i = 0; i < N; i++) {
        cout << *ptr << " ";
        ptr += N - 1; 
    }
    cout << endl;

    // Обчислення кількості парних та непарних елементів
    int count_even = 0, count_odd = 0;
    ptr = &arr[0][0];
    for (int i = 0; i < N * N; i++) {
        if (*ptr % 2 == 0) {
            count_even++;
        } else {
            count_odd++;
        }
        ptr++;
    }
    cout << "Кількість парних елементів: " << count_even << endl;
    cout << "Кількість непарних елементів: " << count_odd << endl;

    return 0;
}
