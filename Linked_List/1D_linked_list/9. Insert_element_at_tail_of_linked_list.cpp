#include <bits/stdc++.h>
using namespace std;

// structure of a node
class Node
{
public:
    int data;
    Node *next;

    Node(int data1) // constructor
    {
        data = data1;
        next = nullptr;
    }
};

// Array to linked list conversion
Node *Array2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = head;
    Node *mover = head;
    for (int i = 1; i < arr.size(); ++i)
    {
        temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// display linked list
void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// insert at tail of linked list
Node *insertAtTail(Node *head, int value)
{
    if (head == NULL)
        return new Node(value); // if head is null then create a new node (head points to new node)

    Node *temp = head;
    while (temp->next != NULL) // reach tail
        temp = temp->next;

    temp->next = new Node(value); // next part of tail will point to inserted element
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5}; // given array

    Node *head = Array2LL(arr); // convert given array to linked list

    int value;
    cout << "Enter the value to be inserted:";
    cin >> value;
    head = insertAtTail(head, value); // insert element at tail

    printLL(head); // display Linked list
}