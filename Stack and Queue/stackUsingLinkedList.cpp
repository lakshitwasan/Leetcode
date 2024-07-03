#include <iostream>
#include <vector>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;
    int size;

    StackNode(int data1)
    {
        data = data1;
        next = NULL;
    }
};

class Stack
{
    StackNode *top;
    int size;

public:
    Stack()
    {
        top = NULL;
        size = 0;
    }

    void Push(int x)
    {
        StackNode *newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
        cout << "Element pushed: " << x << endl;
        size++;
    }

    int Pop()
    {
        if (top == NULL)
        {
            cout << "The stack is empty:" << endl;
            return -1;
        }
        int x = top->data;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        size--;
        return x;
    }

    int Top()
    {
        if (top == NULL)
        {
            cout << "The Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    int Size()
    {
        return size;
    }

    bool Empty()
    {
        return top == NULL;
    }

    void printStack()
    {
        if (top == NULL)
        {
            cout << "The Stack is empty" << endl;
        }

        StackNode *temp = top;
        while (temp)
        {
            cout << temp->data << " | ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.Push(10);
    cout << "Element popped: " << s.Pop() << "\n";
    cout << "Stack size: " << s.Size() << "\n";
    cout << "Stack empty or not? " << s.Empty() << "\n";
    cout << "stack's top element: " << s.Top() << "\n";
    return 0;
}