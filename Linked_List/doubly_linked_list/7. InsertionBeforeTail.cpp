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

Node *insertBeforeHead(Node *head, int value)
{
    Node *temp = head;
    Node *x = new Node(value, head, nullptr);
    head->back = x;
    head = x;
    return head;
}

Node *insertBeforeTail(Node *head, int value)
{
    Node *temp = head;
    if (head == NULL)
        return NULL; // nothing present, insertion not possible

    if (head->next == NULL)                   // only 1 element present i.e. head = tail
        return insertBeforeHead(head, value); // so it becomes insert before head
    while (temp->next != NULL)
        temp = temp->next;
    Node *prev = temp->back;
    Node *x = new Node(value, temp, prev); // create new node x
    temp->back = x;
    prev->next = x;

    return head;
}

int main()
{
    vector<int> arr = {1, 20, 31, 4, 54};
    Node *head = convertArr2DLL(arr);
    int value;
    cout << "Enter value of node to be inserted:";
    cin >> value;
    head = insertBeforeTail(head, value);
    printDLL(head);
}
