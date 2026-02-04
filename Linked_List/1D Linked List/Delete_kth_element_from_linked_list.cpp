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

// delete kth element
Node *deleteK(Node *head, int k)
{
    if (head == NULL)
        return NULL; // if no element present, its not possible to delete anything

    if (k == 1) // for head
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head; // for elements except head position, includes tail
    Node *prev = NULL;
    int count = 1;
    while (temp)
    {
        if (count == k)
        {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
        count++;
    }
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5}; // given array

    Node *head = Array2LL(arr); // convert given array to linked list

    int pos;
    cout << "Enter the position of element to be deleted:";
    cin >> pos;
    head = deleteK(head, pos); // delete kth element

    printLL(head); // display Linked list
}