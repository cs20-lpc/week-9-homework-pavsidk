#include <iostream>
#include <cstdlib>
#include <ctime>
#include "QueueFactory.cpp"
using namespace std;

int main() {
    srand(time(0));

    //simulation 1: arrival and service process
    cout << "----Ticket Counter----" << endl;
    Queue<string>* queueOne = QueueFactory<string>::GetQueue(10);
    
    for (int i=0; i<100; i++) {
        double random = -1.0 + static_cast<double>(rand()) / RAND_MAX * 2.0;
        if (random >= 0) {
            if (queueOne->getLength() == 10) {
                cout << "Queue is full." << endl;
            }
            else {
                cout << "Customer has entered the queue." << endl;
                queueOne->enqueue("customer");
            }
        }
        else {
            if (queueOne->getLength() == 0) {
                cout << "Queue is empty." << endl;
            }
            else {
                cout << "Customer was served and has left the queue." << endl;
                queueOne->dequeue();
            }
        }
    }

    //simulation 2: Bank Service Line
    cout << endl;
    cout << "----Bank Service Line----" << endl;
    Queue<string>* queueTwo = QueueFactory<string>::GetQueue();

    for (int i=0; i<100; i++) {
        double randomer = -1.0 + static_cast<double>(rand()) / RAND_MAX * 3.0;
        if (randomer >= 0) {
            cout << "Customer has entered the queue." << endl;
            queueTwo->enqueue("customer");
        }
        else {
            if (queueTwo->isEmpty()) {
                cout << "Queue is empty." << endl;
            }
            else {
                cout << "Customer was served and has left the queue." << endl;
                queueTwo->dequeue();
            }
        }
    }
    cout << endl;

    delete queueOne;
    delete queueTwo;

}