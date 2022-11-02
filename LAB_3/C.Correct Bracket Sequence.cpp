#include <iostream>
#include <string>

using namespace std;

struct Node
{
    char data;
    Node* next;
    Node(char value)
    {
        data = value;
        next = NULL;
    }
};
struct Stack
{
    Node *head = NULL;
    void push(char x)
    {
        Node *newNode = new Node(x);

        newNode->next=head;

        if(head == NULL)
        {
            head = tail = newNode;
        }
        else{
            newNode -> next = head;
            head = newNode;
        }
    }
    void pop()
    {
        Node* tmp;
        if(head == NULL) head = tail = NULL;
        else{
            tmp = head;
            head = head -> next;
            free(tmp);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Stack stack;
    char a;
    string string;
    while (getline(cin, string)) {
        int size = string.size();
        for (int i = 0; i < size; i++) {
            a = string[i];
            stack.push(a);
        }
        Stack check;
        for (int i = 0; i < size; i++) {
            if (check.head == NULL) {
                a = (stack.head)->data;
                stack.pop();
                check.push(a);

                if (a == '(' || a == '[') {
                    break;
                }
            } else {
                if (stack.head->data == ')' || stack.head->data == ']') {
                    a = (stack.head)->data;
                    stack.pop();
                    check.push(a);
                } else {
                    if (((stack.head)->data == '(' && (check.head)->data == ')') ||
                        ((stack.head)->data == '[' && (check.head)->data == ']')) {
                        stack.pop();
                        check.pop();
                    } else {
                        break;
                    }
                }
            }
            if (stack.head == NULL) break;
        }
        if (check.head == NULL) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
