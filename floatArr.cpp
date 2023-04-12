/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() {
    const int n = 10;
    float* arr = new float[n]; // створення динамічного масиву
    // заповнення масиву випадковими числами в діапазоні (-2, 2)
    for (int i = 0; i < n; i++) {
        arr[i] = ((float)rand() / RAND_MAX) * 4 - 2;
    }
    // виведення масиву на екран
    cout << "Масив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
    // підрахунок кількості додатніх та від'ємних чисел
    int positive = 0, negative = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            positive++;
        } else if (arr[i] < 0) {
            negative++;
        }
    }
    cout << "Додатніх: " << positive << endl;
    cout << "Від'ємних: " << negative << endl;
    delete[] arr; // звільнення пам'яті, виділеної під масив
    return 0;
}
