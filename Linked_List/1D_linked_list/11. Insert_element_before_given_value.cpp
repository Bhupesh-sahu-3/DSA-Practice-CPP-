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

// insert element before given element
Node *insertByValue(Node *head, int ele, int value)
{
    if (head == NULL)  return NULL; // if head is null then insertion not possible

    if (head->data == value)
    {
        Node *temp = new Node(ele);
        temp->next = head;
        head = temp;
        return head;
    }

    Node *temp = head;
    int flag=0;
    while(temp)
    {
        if(temp->next->data == value)
        {
            Node* x = new Node(ele);
            x->next = temp->next;
            temp->next =x;
            flag =1;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
    cout<<"value not found in the linked list!!"<<endl;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5}; // given array

    Node *head = Array2LL(arr); // convert given array to linked list

    int ele;
    cout << "Enter the element to be inserted:";
    cin >> ele;
    int value;
    cout<<"before which value:";
    cin>>value;


    head = insertByValue(head, ele, value); // insert element before given value

    printLL(head); // display Linked list
}