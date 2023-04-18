// 2YearTask.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

bool isLeap(int year) {
    // Перевірка на високосний рік
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        return true;
    else
        return false;
}

int monthLength(int year, int month) {
    // Вектор для зберігання довжини місяців
    vector<int> monthLengths = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Збільшуємо довжину лютого на 1, якщо рік є високосним
    if (isLeap(year))
        monthLengths[1]++;

    // Повертаємо довжину місяця
    return monthLengths[month - 1];
}

int main(void) {
    for (int yr = 2000; yr < 2002; yr++) {
        for (int mo = 1; mo <= 12; mo++)
            cout << monthLength(yr, mo) << " ";
        cout << endl;
    }
    return 0;
}
