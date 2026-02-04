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

// delete tail
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL; // if there is no node present, can't delte anything
                     // if only 1 node present then head = tail, can't delete head
    Node *temp = head;

    while (temp->next->next != NULL)      //reach second last element
    {
        temp = temp->next;
    }
    delete (temp->next);                //delete last element
    temp->next = nullptr;               //now next part of second last element point to null and it becomes the last element
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5}; // given array

    Node *head = Array2LL(arr); // convert given array to linked list

    head = deleteTail(head); // delete tail

    printLL(head); // display Linked list
}