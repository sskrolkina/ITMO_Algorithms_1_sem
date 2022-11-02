#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};
struct Stack
{
    Node *head = NULL;
    void push(int x)
    {
        Node *newNode = new Node;
        newNode->next=head;
        newNode->data = x;
        head = newNode;
    }
    void pop()
    {
        Node* del = head;
        head = head -> next;
        delete del;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Stack stack;
    int a;
    int n;
    cin >> n;
    char action;

    for(int i = 0;i < n;i++){
        cin >> action;
        if(action == '+')
        {
            cin >> a;
            stack.push(a);
        }
        else if(action == '-')
        {
            cout << (stack.head)->data << '\n';
            stack.pop();
        }
    }
    return 0;
}
