#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }

};
struct Queue
{
    Node *head = NULL,*tail = NULL;

    void push(int x)
    {
        Node* newNode = new Node(x);
        if(tail == NULL){
            head = tail = newNode;
            return;
        }
        tail -> next = newNode;
        tail = newNode;
    }
    void pop()
    {
        if(head == NULL)return;
        Node* del = head;
        head = head -> next;
        if(head == NULL){
            tail = NULL;
        }
        delete(del);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Queue queue;
    int a;
    int n;
    cin >> n;
    char action;

    for(int i = 0;i < n;i++){
        cin >> action;
        if(action == '+')
        {
            cin >> a;
            queue.push(a);
        }
        else if(action == '-')
        {
            cout << (queue.head)->data << '\n';
            queue.pop();
        }
    }
    return 0;
}
