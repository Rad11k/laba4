#include <iostream>
#include "array.h"
using namespace std;

int main() {
    Array arr1, arr2;

    arr1.setValue(6);
    arr1.setValue(60);

    arr2.setValue(40);
    arr2.setValue(40);

    // Порівняння ==
    if (arr1 == arr2) {
        cout << "Eq" << endl;
    }

    // Порівняння !=
    if (arr1 != arr2) {
        cout << "Not Eq" << endl;
    }

    // Склеювання масивів
    Array arr3 = arr1 + arr2;
    cout << "arr1 + arr2: " << arr3;

    // Додавання числа до масиву
    Array arr4 = arr1 + 7;
    cout << "arr1 + 7: " << arr4;

    // Віднімання числа з масиву
    Array arr5 = arr2 - 10;
    cout << "arr2 - 10: " << arr5;

    // Постфіксний інкремент
    Array arr6 = arr1++;
    cout << "arr1++ (before): " << arr6;
    cout << "arr1 (after): " << arr1;

    // += оператор
    arr2 += 3;
    cout << "arr2 += 3: " << arr2;

    // Доступ по індексу
    cout << "arr3[0]: " << arr3[0] << endl;
    cout << "arr3[99] (out of bounds): " << arr3[99] << endl;

    // 7 + arr (дружній)
    Array arr7 = 7 + arr1;
    cout << "7 + arr1: " << arr7;

    return 0;
}
