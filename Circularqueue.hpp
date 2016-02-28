/***********************************************************************************
** Author: Patrick Armitage
** Date: 02/27/2016
** Description: CircularQueue class prototype which defines the QueueNode struct,
** the constructor, and the add and remove item functions and print nodes function
***********************************************************************************/

#ifndef CIRCULARQUEUE_HPP
#define CIRCULARQUEUE_HPP

struct QueueNode {
    QueueNode *nextNode;
    QueueNode *prevNode;
    int value;
};

class Circularqueue {
 private:
    QueueNode *front;
    QueueNode *back;
 public:
    Circularqueue();
    int getFront();
    void addBack(int value);
    int removeFront();
    void printNodes();
};

#endif
