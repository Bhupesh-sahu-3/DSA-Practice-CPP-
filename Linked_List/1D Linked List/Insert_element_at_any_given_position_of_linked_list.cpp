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

// insert element at given position of linked list
Node *insertAtK(Node *head, int value, int k)
{
    if (head == NULL)
        return new Node(value); // if head is null then create new node and head points to it

    if (k == 1)
    {
        Node *temp = new Node(value);
        temp->next = head;
        head = temp;
        return head;
    }

    Node *temp = head;
    int count=1;
    int flag=0;
    while(temp)
    {
        if(count==k-1)
        {
            Node* x = new Node(value);
            x->next = temp->next;
            temp->next =x;
            flag =1;
            break;
        }
        temp=temp->next;
        count++;
    }
    if(flag==0)
    cout<<"position not found! Enter valid position !!"<<endl;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5}; // given array

    Node *head = Array2LL(arr); // convert given array to linked list

    int value;
    cout << "Enter the value to be inserted:";
    cin >> value;
    int pos;
    cout << "Enter position";
    cin >> pos;
    head = insertAtK(head, value, pos); // insert element at given position

    printLL(head); // display Linked list
}