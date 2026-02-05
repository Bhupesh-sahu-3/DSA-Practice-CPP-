// IMPORTANT : Node given will never be the HEAD node

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convertArr2DLL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *temp = NULL;
    Node *prev = head;
    for (int i = 1; i < arr.size(); ++i)
    {
        temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// IMPORTANT : Node given for deletion will never be the HEAD node
Node *deleteByValue(Node *head, int value)
{
    if (head == NULL)
        return NULL;

    Node *temp = head;
    while (temp)
    {
        if (temp->data == value)
            break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL) // tail
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return head;
    }
    // other nodes except tail and head
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;

    return head;
}

int main()
{
    vector<int> arr = {1, 20, 31, 4, 54};
    Node *head = convertArr2DLL(arr);
    int value;
    cout << "Enter value of node to be deleted:";
    cin >> value;
    head = deleteByValue(head, value);
    printDLL(head);
}
