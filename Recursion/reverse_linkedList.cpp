#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <thread>
#include <chrono>
#include "Node.h"

using namespace std;



void print(Node* root)
{
    cout << "O-> ";
    for (auto*i = root; i != nullptr; i = i->next)
    {
        this_thread::sleep_for(chrono::milliseconds(200));
        cout << i->val << " -> " << flush;
    }
    cout << "XX" << endl;
    cout << endl;
}

Node* reverseLinkedList(Node* root)
{
    if (root == nullptr || root->next == nullptr)
    {
        return root;
    }
    Node* p = reverseLinkedList(root->next);
    root->next->next = root;
    root->next = nullptr;
    return p;
}

int main()
{
    // @author Ayush Sharma (ayush08642)
    //Let's start!
    Node* root = new Node(5);
    root->next = new Node(6);
    root->next->next = new Node(7);
    root->next->next->next = new Node(8);
    root->next->next->next->next = new Node(9);

    print(root);
    root = reverseLinkedList(root);
    print(root);

    return 0;
}