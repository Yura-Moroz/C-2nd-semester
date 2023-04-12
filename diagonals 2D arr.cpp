/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int rows = 3, cols = 3;

    int **matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    srand(time(nullptr)); 
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 21 - 10; // Заповнюємо значеннями з діапазону (-10, 10)
        }
    }

    int count_even = 0, count_odd = 0; 
    cout << "Матриця:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout.width(4);
            cout << matrix[i][j];

            // Знаходимо елементи на головній діагоналі
            if (i == j) {
                cout << " [головна]";
            }

            // Знаходимо елементи на побічній діагоналі
            if (i + j == rows - 1) {
                cout << " [побічна]";
            }

            // Знаходимо парні та непарні елементи
            if (matrix[i][j] % 2 == 0) {
                count_even++;
            } else {
                count_odd++;
            }
        }
        cout << endl;
    }

    cout << "Кількість парних елементів: " << count_even << endl;
    cout << "Кількість непарних елементів: " << count_odd << endl;

    // Звільняємо пам'ять, що була виділена для масиву
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
