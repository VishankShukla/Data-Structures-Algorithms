#include<bits/c++.h>
using namespace std;

class Stack {
public:
    int arr[100];
    int top = -1;

    // Push element
    void push(int x) {
        if (top == 99) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    // Pop element
    int pop() {
        if (top == -1) {
            cout << "Stack Empty" << endl;
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }

    // Top element
    int peek() {
        if (top == -1) {
            cout << "Stack Empty" << endl;
            return -1;
        }
        return arr[top];
    }

    // Check empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;

    s.push(5);
    s.push(10);

    cout << "Top = " << s.peek() << endl;
    cout << "Pop = " << s.pop() << endl;
    cout << "Top = " << s.peek() << endl;

    if (s.isEmpty())
        cout << "Stack is Empty";
    else
        cout << "Stack is Not Empty";

    return 0;
}