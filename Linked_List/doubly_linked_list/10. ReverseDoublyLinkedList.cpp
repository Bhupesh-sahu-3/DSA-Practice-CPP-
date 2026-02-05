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

// Method 1 - using stack
// o(n) time and o(n)space
Node *reverseUsingStack(Node *head)
{
    stack<int> st;
    Node *temp = head;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

// Method2 - using single pass
// o(n) time and o(1) space
Node *reverseLinks(Node *head)
{
    Node *current = head;
    Node *temp = NULL;

    while (current != NULL)
    {
        temp = current->back;
        current->back = current->next;
        current->next = temp;
        current = current->back;
    }
    return temp->back;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Node *head = convertArr2DLL(arr);

    // head = reverseUsingStack(head);
    head = reverseLinks(head);

    printDLL(head);
}
