#include <iostream>
#include <string>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

struct Stack {
    Node *head = NULL;

    void push(int x) {
        Node *newNode = new Node(x);

        newNode->next = head;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop() {
        Node *tmp;
        if (head == NULL) head = tail = NULL;
        else {
            tmp = head;
            head = head->next;
            free(tmp);
        }
    }
};

int main() {
    Stack stack;
    string string;
    char symbol;
    int number1;
    int number2;
    int result;
    getline(cin, string);
    for (int i = 0; i < string.size(); i++) {
        symbol = string[i];
        if (symbol - '0' > -1) {
            stack.push(symbol - '0');
        } else {
            switch (symbol) {
                case '+':
                    number1 = (stack.head)->data;
                    stack.pop();
                    number2 = (stack.head)->data;
                    stack.pop();
                    result = number1 + number2;
                    stack.push(result);
                    break;
                case '-':
                    number1 = (stack.head)->data;
                    stack.pop();
                    number2 = (stack.head)->data;
                    stack.pop();
                    result = number2 - number1;
                    stack.push(result);
                    break;
                case '*':
                    number1 = (stack.head)->data;
                    stack.pop();
                    number2 = (stack.head)->data;
                    stack.pop();
                    result = number1 * number2;
                    stack.push(result);
                    break;
            }
        }
    }
    cout << (stack.head)->data;
    return 0;
}
