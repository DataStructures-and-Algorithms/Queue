//
// Created by Hayden Huynh on 11/12/19.
//

#ifndef QUEUE_ARRAYQUEUE_H
#define QUEUE_ARRAYQUEUE_H

#include <iostream>

class ArrayQueue {

private:

    int* arr;
    int currSize;
    int capacity;
    int first;
    int last;

public:

    ArrayQueue(int size);

    void enqueue(int val);

    int dequeue();

    int getFirst();

    int getLast();

    bool isFull();

    bool isEmpty();

    void printQueue();

    void deleteQueue();

};

ArrayQueue::ArrayQueue(int size) {
    first = -1;
    last = -1;
    currSize = 0;
    this->capacity = size;
    arr = new int[size];
}

void ArrayQueue::enqueue(int val) {
    if (isFull()) {
        std::cout << "\n\nQueue is full.\n\n";
    }
    else {
        last = (last+1) % capacity;
        if (currSize == 0) {
            first++;
            arr[first] = val;
        }
        else {
            arr[last] = val;
        }
        currSize++;
    }
}

int ArrayQueue::dequeue() {
    if (isEmpty()) {
        std::cout << "\n\nQueue is empty.\n\n";
    }
    else {
        int returnVal = arr[first];
        if (currSize == 1) {
            first = -1;
            last = -1;
        }
        else {
            first = (first+1) % capacity;
        }
        currSize--;
        return returnVal;
    }
}

int ArrayQueue::getFirst() {
    if (!isEmpty()) {
        return arr[first];
    }
}

int ArrayQueue::getLast() {
    if (!isEmpty()) {
        return arr[last];
    }
}

bool ArrayQueue::isFull() {
    return currSize == capacity;
}

bool ArrayQueue::isEmpty() {
    return currSize == 0;
}

void ArrayQueue::printQueue() {
    if (isEmpty()) {
        std::cout << "\n\nQueue is empty.\n\n";
    }
    else {
        int i = first;
        if (first <= last) {
            for (i; i <= last; i++) {
                std::cout << arr[i] << " ";
            }
        }
        else {
            for (i; i < capacity; i++) {
                std::cout << arr[i] << " ";
            }
            for (int i = 0; i <= last; i++) {
                std::cout << arr[i] << " ";
            }
        }
    }
}

void ArrayQueue::deleteQueue() {
    currSize = 0;
    capacity = 0;
    first = -1;
    last = -1;
    delete[] arr;
}

#endif //QUEUE_ARRAYQUEUE_H
