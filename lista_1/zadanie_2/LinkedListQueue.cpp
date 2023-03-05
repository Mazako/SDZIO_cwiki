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
        this->data = data;
    }
};

template <class T>
class LinkedListQueue
{
public:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

    T *pop()
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        T *data = &this->head->data;
        auto *headPtr = this->head;
        head = head->next;
        delete headPtr;
        if (head == nullptr)
        {
            tail = head;
        }
        return data;
    }

    void push(T data)
    {
        auto *newNode = new Node<T>(data);
        auto *tailPtr = tail;
        tail = newNode;
        if (head != nullptr)
        {
            tailPtr->next = tail;
        }
        else
        {
            head = tail;
        }
    }

    void printQueue()
    {
        auto *nodePtr = head;
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
    LinkedListQueue<string> *queue = new LinkedListQueue<string>();
    string msg = "";
    do
    {
        cin >> msg;
        if (msg == "/")
        {
            queue->pop();
        }
        else
        {
            queue->push(msg);
        }
        queue->printQueue();
    } while (msg != "exit");

    return 0;
}