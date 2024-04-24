#include "LinkedList.h"

using namespace std;

int main()
{
    vector<int> v({1, 2, 3, 4, 5, 6, 7});
    LinkedList l(v);

    cout << "print list" << endl;
    l.print();
    cout << "add node" << endl;
    l.addNode(11);
    l.print();


    //cout << "Delete last node" << endl;
    l.deleteLastNode();
    l.print();


    cout << "Delete a certain node." << endl;
    l.deleteNode(4, 5);
    l.print();


    cout << "get head" << endl;
    Node *head = l.getHead();
    printf("Head: %d\n", head->val);

    cout << "get tail" << endl;
    Node *tail = l.getTail();
    printf("Tail: %d\n", tail->val);
    l.print();


    cout << "Reverse the linkedlist" << endl;
    Node *root = l.reverseList(l.getHead());
    l.print();


    cout << "Clear the linkedlist" << endl;
    l.clear(l.getHead());
    l.print();
}