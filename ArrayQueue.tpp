#include "ArrayQueue.hpp"

template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    maxSize = i;
    buffer = new T[maxSize];
    frontIndex = 0;
    backIndex = 0;
    this->length = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO
    if (this->length ==0) {
        throw string("back: error, queue is empty, cannot access the back");
    }
    return buffer[backIndex];
}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    frontIndex = 0;
    backIndex = 0;
    this->length = 0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO
    maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    buffer = new T[maxSize];
    for (int i = 0; i < this->length; i++) {
        buffer[i] = copyObj.buffer[(copyObj.frontIndex + i) % copyObj.maxSize];
    }
    frontIndex = 0;
    backIndex = this->length > 0 ? this->length - 1 : 0;
}

template <typename T>
void ArrayQueue<T>::dequeue() {
    if (this->length == 0) {
        throw string("Dequeue: error, queue is empty");
    }
    frontIndex = (frontIndex + 1);
    this->length--;
    if (this->length == 0) {
        frontIndex = 0;
        backIndex = 0;
    }
}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (this->length == maxSize) {
        throw string("Enqueue: error, queue is full");
    }
    if (this->length != 0) {
        backIndex = (backIndex + 1);
    }
    buffer[backIndex] = elem;
    this->length++;
}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if (this->length == 0) {
        throw string("front: error, queue is empty, cannot access the front");
    }
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}


