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

Node *insertBeforeNode(Node *head, int value, int node)
{
    Node *temp = head;
    if (head == NULL)
        return NULL; // nothing present, insertion not possible

    //you are not supposed to insert before head as it changes the head
    int flag = 0;
    while (temp != NULL)
    {
        if (temp->data == node)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag == 0)
    {
        cout << "Node entered is invalid" << endl;
        return head;
    }

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
    int node;
    cout << "Enter value to be inserted:";
    cin >> value;
    cout << "Enter node before which value should be inserted:";
    cin >> node;
    head = insertBeforeNode(head, value, node);
    printDLL(head);
}
