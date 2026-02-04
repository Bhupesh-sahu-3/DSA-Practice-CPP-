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

    Node *Array2LL(vector<int> arr)
    {
        Node *head = new Node(arr[0]);
        Node* temp = head;
        Node* mover = head;
        for (int i = 1; i < arr.size(); ++i)
        {
            temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }

    void printLL(Node* head)
    {
        Node* temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        
    }

    int main()
    {
        vector<int> arr = {1, 2, 3, 4, 5}; // given array
        Node *head = Array2LL(arr);
        printLL(head);
    }