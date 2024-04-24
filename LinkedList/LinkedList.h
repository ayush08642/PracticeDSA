#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include "Node.h"
using namespace std;

class LinkedList
{
    Node *head = nullptr;
    Node *tail = nullptr;
    int32_t length = 0;

public:
    LinkedList();
    LinkedList(vector<int> &vdata);
    LinkedList(int data);

    void addNode(int data);
    void deleteNode(int pos, int data);
    void deleteLastNode();
    void clear(Node *root);
    void deleteAllNodes();
    int32_t getLength() const;
    Node *getHead() const;
    Node *getTail() const;
    bool isEmpty() const;
    void print() const;

    // To do: LinkedList Reveresal.
    Node *reverseList(Node *head);
};