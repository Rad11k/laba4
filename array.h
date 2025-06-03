#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;

class Array {
private:
    int initialSize;
    int step;
    int* data;
    int currentIndex;

public:
    Array(int size = 10, int step = 5);
    Array(const Array& other);
    ~Array();
    Array& operator=(const Array& other);

    void showElements();
    int getSize();
    int getElemSize();
    void setValue(int val);
    void setArray(int* pArr, int size);
    void expandArray(int newSize);

    // Оператори
    Array operator+(const Array& other) const;   // arr1 + arr2
    Array operator+(int val) const;              // arr1 + 7
    Array operator-(int val) const;              // arr1 - 7
    bool operator==(const Array& other) const;   // arr1 == arr2
    bool operator!=(const Array& other) const;   // arr1 != arr2
    Array operator++(int);                       // arr1++
    Array& operator+=(int val);                  // arr1 += 7
    int operator[](int index) const;             // arr1[0]

    friend ostream& operator<<(ostream& os, const Array& arr); 
    friend Array operator+(int val, const Array& arr);         
};

#endif