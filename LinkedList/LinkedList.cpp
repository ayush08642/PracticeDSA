#include "LinkedList.h"

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->length = 0;
}

LinkedList::LinkedList(vector<int> &vdata)
{
    for (auto data : vdata)
    {
        this->addNode(data);
        this->length++;
    }
}

LinkedList::LinkedList(int data)
{
    this->addNode(data);
    this->length++;
}

void LinkedList::addNode(int data)
{
    Node *temp = new Node(data);
    if (this->head == nullptr)
    {
        this->head = temp;
        this->length++;
        this->tail = temp;
        return;
    }
    this->tail->next = temp;
    this->tail = this->tail->next;
    this->length++;
}

void LinkedList::deleteNode(int pos, int data)
{
    int32_t i = 0;
    Node *ni = nullptr, *prev = nullptr;
    for (ni = this->head, prev = this->head; i != pos; i++)
    {
        prev = ni;
        ni = ni->next;
    }
    prev->next = ni->next;
    free(ni);
}

void LinkedList::deleteLastNode()
{
    Node *tmp = nullptr;
    if (head == nullptr)
    {
        return;
    }
    if (this->length == 1)
    {
        free(this->head);
        this->head = nullptr;
        this->tail = nullptr;
    }

    // cout << "\nDeleting the last node.. \n O-> ";
    for (tmp = this->head; tmp->next->next != nullptr; tmp = tmp->next)
        ;
    // printf("tmp: %d\n", tmp->next->val);

    free(tmp->next);
    tmp->next = nullptr;
    this->tail = tmp;

    // Decrement length;
    this->length--;
}

void LinkedList::clear(Node *root)
{
    if (root == nullptr || root->next == nullptr)
    {
        if (root != nullptr)
        {
            free(root);
            root = nullptr;
            return;
        }
        return;
    }

    this->clear(root->next);
    this->head = nullptr;
    free(root);
    root = nullptr;
    return;
}

int32_t LinkedList::getLength() const
{
    return this->length;
}

Node *LinkedList::getHead() const
{
    return this->head;
}

Node *LinkedList::getTail() const
{
    return this->tail;
}

bool LinkedList::isEmpty() const
{
    return this->length == 0;
}

void LinkedList::print() const
{
    cout << "O-> ";
    for (Node *i = this->head; i != nullptr; i = i->next)
    {
        cout << i->val << " -> ";
    }
    cout << "XX" << endl;
}

Node *LinkedList::reverseList(Node *root)
{
    if (root == nullptr || root->next == nullptr)
    {
        return root;
    }
    this->head = this->reverseList(root->next);
    root->next->next = root;
    root->next = nullptr;
    return this->head;
}