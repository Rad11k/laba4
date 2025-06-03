#include <iostream>
#include "array.h"
using namespace std;

Array::Array(int size, int step) {
    if (size <= 0) size = 10;
    if (step <= 0) step = 5;

    this->initialSize = size;
    this->step = step;
    this->data = new int[size];
    this->currentIndex = 0;
}

Array::Array(const Array& other) {
    initialSize = other.initialSize;
    step = other.step;
    currentIndex = other.currentIndex;
    data = new int[initialSize];
    for (int i = 0; i < currentIndex; i++) {
        data[i] = other.data[i];
    }
}

Array::~Array() {
    delete[] data;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        initialSize = other.initialSize;
        step = other.step;
        currentIndex = other.currentIndex;
        data = new int[initialSize];
        for (int i = 0; i < currentIndex; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

void Array::expandArray(int newSize) {
    if (newSize <= initialSize) return;
    int* temp = new int[newSize];
    for (int i = 0; i < currentIndex; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    initialSize = newSize;
}

void Array::setValue(int val) {
    if (currentIndex >= initialSize) {
        expandArray(initialSize + step);
    }
    data[currentIndex++] = val;
}

void Array::setArray(int* pArr, int size) {
    for (int i = 0; i < size; i++) {
        setValue(pArr[i]);
    }
}

void Array::showElements() {
    for (int i = 0; i < currentIndex; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int Array::getSize() {
    return initialSize;
}

int Array::getElemSize() {
    return currentIndex;
}

// ===== Оператори =====

Array Array::operator+(const Array& other) const {
    Array result(currentIndex + other.currentIndex, step);
    for (int i = 0; i < currentIndex; i++) result.setValue(data[i]);
    for (int i = 0; i < other.currentIndex; i++) result.setValue(other.data[i]);
    return result;
}

Array Array::operator+(int val) const {
    Array result(*this);
    for (int i = 0; i < result.currentIndex; i++) {
        result.data[i] += val;
    }
    return result;
}

Array operator+(int val, const Array& arr) {
    return arr + val;
}

Array Array::operator-(int val) const {
    Array result(*this);
    for (int i = 0; i < result.currentIndex; i++) {
        result.data[i] -= val;
    }
    return result;
}

bool Array::operator==(const Array& other) const {
    if (currentIndex != other.currentIndex) return false;
    for (int i = 0; i < currentIndex; i++) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

bool Array::operator!=(const Array& other) const {
    return !(*this == other);
}

Array Array::operator++(int) {
    Array temp(*this);
    for (int i = 0; i < currentIndex; i++) {
        data[i]++;
    }
    return temp;
}

Array& Array::operator+=(int val) {
    for (int i = 0; i < currentIndex; i++) {
        data[i] += val;
    }
    return *this;
}

int Array::operator[](int index) const {
    if (index < 0 || index >= currentIndex) {
        return data[0];
    }
    return data[index];
}

ostream& operator<<(ostream& os, const Array& arr) {
    for (int i = 0; i < arr.currentIndex; i++) {
        os << arr.data[i] << " ";
    }
    os << endl;
    return os;
}
