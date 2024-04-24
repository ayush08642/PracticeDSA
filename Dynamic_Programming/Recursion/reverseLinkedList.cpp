#include "../../LinkedList/LinkedList.h"

Node* reverseLinkedList(Node* root)
{
    if (root == nullptr || root->next == nullptr)
    {
        return root;
    }
    Node* head = reverseLinkedList(root->next);
    root->next->next = root;
    root->next = nullptr;
    return head;
}

//int main()
//{
//    vector<int> nums({1, 2, 3, 5, 10, 1024, 100000});
    
//    LinkedList list(nums);
//    Node* newHead = reverseLinkedList(list.getHead());

//    list.print();

//}