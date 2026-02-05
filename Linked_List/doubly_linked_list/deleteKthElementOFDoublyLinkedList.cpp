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

Node *deleteHead(Node *head)
{
    Node *temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr;
    delete temp;
    return head;
}

Node *deleteTail(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    Node *prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

Node *deleteK(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    int count = 0;
    Node *temp = head;
    while (temp)
    {
        count++;
        if (count == k)
            break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;

    if (prev == NULL && front == NULL) // deleting single element so simply return NULL
        return NULL;
    else if (prev == NULL) // head
    {
        return deleteHead(head);
    }
    else if (front == NULL) // tail
    {
        return deleteTail(head);
    }

    else // any other element except the head and tail
    {
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        delete temp;
    }

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArr2DLL(arr);
    int k;
    cout << "Enter node to be deleted:";
    cin >> k;
    head = deleteK(head, k);
    printDLL(head);
}
