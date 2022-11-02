#include <iostream>
#include <string>

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
    Stack check;
    int a;
    int n;
    cin >> n;
    string action;

    for(int i = 0;i < n;i++){
        cin >> action;
        if(action == "+")
        {
            cin >> a;
            if (stack.head == NULL){
                check.push(a);
            }
            stack.push(a);

            if(a > check.head->data){
                check.push(a);
            }
            else{
                check.push(check.head->data);
            }
        }
        else if(action == "-")
        {
            stack.pop();
            check.pop();
        }
        else if(action == "max"){
            cout << (check.head)->data << "\n";
        }
    }
    return 0;
}
