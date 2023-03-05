#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next = nullptr;
    Node(T data)
    {
        this-> data = data;
    }
};

template<class T>
class LinkedListStack
{
public:
    Node<T> *head = nullptr;
    
    void push(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode; 
    }

    T* pop()
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        T data = head->data;
        auto* headPtr = head;
        head = head->next;
        return &data;
    }

    void printStack()
    {
        auto* nodePtr = head;
        while (nodePtr)
        {
            cout << nodePtr->data << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }

};

int main()
{
    LinkedListStack<string> *stack = new LinkedListStack<string>();
    string msg = "";
    do {
        cin >> msg;
        if (msg == "/")
        {
            stack->pop();
        }
        else
        {
            stack->push(msg);
        }
        stack->printStack();
    } while (msg != "exit");

    return 0;
}