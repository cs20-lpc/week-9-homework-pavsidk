#include "LinkedQueue.hpp"

template <typename T>
LinkedQueue<T>::LinkedQueue() {
    // TODO
    head = nullptr;
    last = nullptr;

    this->length = 0;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedQueue<T>& LinkedQueue<T>::operator=(const LinkedQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedQueue<T>::~LinkedQueue() {
    clear();
}

template <typename T>
T LinkedQueue<T>::back() const {
    // TODO
    if (head == nullptr) {
        throw string("back: error, queue is empty, cannot access the back");
    }
    return last->value;
}

template <typename T>
void LinkedQueue<T>::clear() {
    // TODO
    Node* n = head;
    Node* prev = nullptr;

    while (n != nullptr) {
        prev = n;
        n = n->next;
        delete prev;
    }

    this->length = 0;
    head = nullptr;
    last = nullptr;
}

template <typename T>
void LinkedQueue<T>::copy(const LinkedQueue<T>& copyObj) {
    // TODO
    head = nullptr;
    last = nullptr;
    Node* copyCurr = copyObj.head;
    while(copyCurr != nullptr) {
        Node* n = new Node(copyCurr->value);
        n->next = nullptr;
        if (head == nullptr) {
            head = n;
        } else {
            last->next = n;
        }

        last = n;
        copyCurr = copyCurr->next;
    }

    this->length = copyObj.length;
}

template <typename T>
void LinkedQueue<T>::dequeue() {
    // TODO
    if (head == nullptr) {
        throw string("dequeue: error, queue is empty");
    }

    Node* curr = head;
    head = curr->next;
    delete curr;

    if (head == nullptr) {
        last = nullptr;
    }
    this->length--;
}

template <typename T>
void LinkedQueue<T>::enqueue(const T& elem) {
    // TODO
    Node* n = new Node(elem);
    n->next = nullptr;
    this->length++;

    if (head == nullptr) {
        head = n;
        last = n;
        return;
    }

    last->next = n;
    last = n;
}

template <typename T>
T LinkedQueue<T>::front() const {
    // TODO
    if (head == nullptr) {
        throw string("front: error, queue is empty, cannot access the front");
    }

    return head->value;
}

template <typename T>
int LinkedQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedQueue<T>::isEmpty() const {
    return this->length == 0;
}
