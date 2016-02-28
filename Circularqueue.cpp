/*******************************************************************************
** Author: Patrick Armitage
** Date: 02/27/2016
** Description: Queue methods file which defines the methods of the
** Queue class that were prototyped within the Queue header file
*******************************************************************************/
#include <iostream>

#include "Circularqueue.hpp"

using std::cout;
using std::endl;

/*----------------------------------------------------------------------------*/
/*
    Function Name: Circularqueue
    Function Parameters: N/A
    What the function does: creates a new QueueNode, and since it is the first
                            node in the CircularQueue, sets its next and prev
                            nodes to itself, and the CircularQueue's front and
                            back nodes to itself
*/
Circularqueue::Circularqueue() {
    QueueNode *frontNode = new QueueNode;

    frontNode->value = -1;
    frontNode->nextNode = frontNode;
    frontNode->prevNode = frontNode;
    front = frontNode;
    back = frontNode;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: getFront
    Function Parameters: N/A
    What the function does: finds the current front node, and if its value is
                            less than 0, finds the next node in the stack until
                            a '>= 0' value is returned.  If another node is found
                            with a '>= 0' value, sets that node as the new front
                            node, returning the value whichever node is found,
                            else returns -1
*/
int Circularqueue::getFront() {
    QueueNode *curNode = front;
    int value = curNode->value;
    while (value < 0) {
        curNode = curNode->nextNode;
        if (curNode != front) {
            value = curNode->value;
        } else {
            return -1;
        }
    }

    front = curNode;
    return value;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: addBack
    Function Parameters: value integer
    What the function does: finds the current back node and checks first to see
                            if it is equal to the front node, in which case if
                            the front node has a value of -1, skip ahead to set
                            the back node's (front node's) value to the supplied
                            parameter.  Else, enters a while loop that continues
                            to find the nextNode and its value until either the
                            node has a value of -1, in which case the loop is
                            exited and that node is populated with the value
                            param, ELSE, no empty node is found, and createNode
                            bool is set to true.  If createNode is true, we
                            instantiate a new node with the value of value param,
                            setting its prevNode to frontNode's prevNode and its
                            nextNode node to front (it sits between frontNode
                            and its prevNode), and linking frontNode and prevNode
                            to the new node also, then returns early.
*/
void Circularqueue::addBack(int value) {
    QueueNode *nextBack = back;
    int nextValue = nextBack->value;
    bool createNode = false;

    if (nextBack != front) {
        while (nextValue > -1) {
            nextBack = nextBack->nextNode;
            if (nextBack != front) {
                nextValue = nextBack->value;
            } else {
                createNode = true;
                break;
            }
        }
    } else if (nextValue > -1) {
        createNode = true;
    }

    if (createNode == true) {
        nextBack = new QueueNode;
        nextBack->value = value;
        nextBack->prevNode = front->prevNode;
        nextBack->nextNode = front;
        front->prevNode->nextNode = nextBack;
        front->prevNode = nextBack;
        back = nextBack;
        return;
    }

    nextBack->value = value;
    back = nextBack;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: removeFront
    Function Parameters: N/A
    What the function does: gets the front node and its value, and sets its
                            value to -1, setting the new front node to nextNode
                            and returning the old front node's value
*/
int Circularqueue::removeFront() {
    QueueNode *frontNode = front;
    int value = frontNode->value;
    frontNode->value = -1;
    front = frontNode->nextNode;

    return value;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: printNodes
    Function Parameters: N/A
    What the function does: finds the front node, then enters a do-while loop,
                            printing the current found node's number and value,
                            and incrementing the count var until the current
                            found node is the front node (I.E. we have gone
                            "full circle" ;) )
*/
void Circularqueue::printNodes() {
    QueueNode *curFront = front;

    int count = 1;

    do {
        cout << "QueueNode " << count << " has value " << curFront->value << endl;
        curFront = curFront->nextNode;
        count++;
    } while (curFront != front);
}
