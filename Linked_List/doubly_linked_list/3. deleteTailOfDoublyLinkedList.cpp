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

Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL; // return null or we can delete as well if only head present

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    Node *prev = temp->back;
    prev->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArr2DLL(arr);
    head = deleteTail(head);
    printDLL(head);
}
