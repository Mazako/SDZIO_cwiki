#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *previous;
    Node *next;
    Node(T data)
    {
        this->data = data;
        this->previous = nullptr;
        this->next = nullptr;
    }
};

template <class T>
void print(Node<T> *headNode);

template <class T>
void append(Node<T> **headRef, T data);

template <class T>
void push(Node<T> **headRef, T data);

template <class T>
void insertAfter(Node<T> *node, T data);

template <class T>
void deleteNode(Node<T> *node);

void appendTest();

void pushTest();

void insertAfterTest();

void deleteTest();

void assert(bool test, int number);

int main()
{
    appendTest();
    pushTest();
    insertAfterTest();
    deleteTest();

    return 0;
}

template <class T>
void print(Node<T> *headNode)
{
    Node<T> *nodePtr = headNode;
    while (nodePtr)
    {
        cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    }
    cout << endl;
}

template <class T>
void append(Node<T> **headRef, T data)
{
    Node<T> *newNode = new Node<T>(data);
    Node<T> *nodePtr = *headRef;
    if (*headRef == NULL)
    {
        *headRef = newNode;
        return;
    }
    while (nodePtr->next != nullptr)
    {
        nodePtr = nodePtr->next;
    }
    nodePtr->next = newNode;
    newNode->previous = nodePtr;
}

template <class T>
void push(Node<T> **headRef, T data)
{
    Node<T> *newNode = new Node(data);

    if (*headRef != nullptr)
    {
        (*headRef)->previous = newNode;
        newNode->next = *headRef;
    }
    *headRef = newNode;
}

template <class T>
void insertAfter(Node<T> *node, T data)
{
    auto *newNode = new Node(data);
    if (node->next == nullptr)
    {
        node->next = newNode;
        newNode->previous = node;
        return;
    }
    newNode->next = node->next;
    newNode->previous = node;
    node->next->previous = newNode;
    node->next = newNode;
}

template <class T>
void deleteNode(Node<T> *node)
{
    if (node->next != nullptr && node->previous != nullptr)
    {
        node->next->previous = node->previous;
        node->previous->next = node->next;
    }
    else if (node->next == nullptr)
    {
        node->previous->next = nullptr;
    }
    else if (node->previous == nullptr)
    {
        node->next->previous = nullptr;
    }
    delete node;
}

void appendTest()
{
    cout << "Double linked list push to end test" << endl;
    Node<int> *headNode = nullptr;
    append(&headNode, 0);
    append(&headNode, 1);
    bool test1 = headNode->data == 0;
    bool test2 = headNode->next->data == 1;
    assert(test1, 1);
    assert(test2, 2);
}

void pushTest()
{
    cout << "Push to begin of Double linked list test" << endl;
    Node<int> *head = nullptr;
    push(&head, 0);
    bool test1 = head->data == 0;
    push(&head, 1);
    bool test2 = head->data == 1 && head->next->data == 0;
    print(head);
    assert(test1, 1);
    assert(test2, 2);
}

void insertAfterTest()
{
    cout << "Insert after list test. should be 0 1 2 3 4 AND 4 3 2 1 0" << endl;
    Node<int> *head = new Node<int>(0);
    Node<int> *n1 = new Node<int>(1);
    Node<int> *n3 = new Node<int>(3);
    head->next = n1;
    n1->previous = head;
    n1->next = n3;
    n3->previous = n1;
    insertAfter(n1, 2);
    insertAfter(n3, 4);
    print(head);
    Node<int> *ptr = n3->next;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->previous;
    }
    cout << endl;
}

void deleteTest()
{
    cout << "Deletion of node in list test" << endl;

    Node<int> *n1 = new Node<int>(1);
    Node<int> *n2 = new Node<int>(2);
    Node<int> *n3 = new Node<int>(3);
    Node<int> *n4 = new Node<int>(4);

    n1->next = n2;
    n2->previous = n1;
    n2->next = n3;
    n3->previous = n2;
    n3->next = n4;
    n4->previous = n3;

    deleteNode(n2);
    print(n1);
    deleteNode(n4);
    print(n1);
    deleteNode(n1);
    print(n3);
}

void assert(bool test, int number)
{
    cout << "\tTest " << number;
    if (test)
    {
        cout << " passed\n";
    }
    else
    {
        cout << " failed\n";
    }
}
