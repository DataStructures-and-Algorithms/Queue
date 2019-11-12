//
// Created by Hayden Huynh on 11/12/19.
//

#ifndef QUEUE_LINKEDLISTQUEUE_H
#define QUEUE_LINKEDLISTQUEUE_H

#include "SingleLinkedList.h"

class LinkedListQueue {

private:
    int currSize;
    SingleLinkedList list;

public:
    LinkedListQueue();

    void enqueue(int val);

    int dequeue();

    int getFirst();

    int getLast();

    bool isEmpty();

    void deleteQueue();

};

LinkedListQueue::LinkedListQueue() {
    currSize = 0;
}

void LinkedListQueue::enqueue(int val) {
    list.insert(val, currSize);
    currSize++;
}

int LinkedListQueue::dequeue() {
    if (currSize == 0) {
        std::cout << "\n\nQueue is empty.\n\n";
    }
    else {
        int returnVal = list.getHeadValue();
        list.deleteNode(0);
        return returnVal;
    }
}

int LinkedListQueue::getFirst() {
    if (currSize == 0) {
        std::cout << "\n\nQueue is empty.\n\n";
    }
    else {
        return list.getHeadValue();
    }
}

int LinkedListQueue::getLast() {
    if (currSize == 0) {
        std::cout << "\n\nQueue is empty.\n\n";
    }
    else {
        return list.getTailValue();
    }
}

bool LinkedListQueue::isEmpty() {
    return currSize == 0;
}

void LinkedListQueue::deleteQueue() {
    currSize = 0;
    list.deleteList();
}

#endif //QUEUE_LINKEDLISTQUEUE_H
