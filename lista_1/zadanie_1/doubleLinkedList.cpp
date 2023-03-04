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
void printList(Node<T> *firstNode);

template <class T>
Node<T> *search(Node<T> *firstNode, int index);

template <class T>
void addAnyNode(Node<T> *firstNode, Node<T> *newNode, int index);

template <class T>
void removeNode(Node<T> *firstNode, int index);

void testPrintList();

void testSearch();

void testAddAnyNode();

void testRemoveNode();

int main()
{
    return 0;
}

template <class T>
void printList(Node<T> *firstNode)
{
    Node<T> *nodePtr = firstNode;
    while (nodePtr)
    {
        cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    }
}

template <class T>
Node<T> *search(Node<T> *firstNode, int index)
{
    Node<T> *nodePtr = firstNode;
    for (int i = 0; i < index; i++)
    {
        nodePtr = nodePtr->next;
        if (nodePtr == nullptr)
        {
            throw invalid_argument("Array index out of bound");
        }
    }
}

void testPrintList()
{
    Node<string> *n1 = new Node<string>("ciesc");
    Node<string> *n2 = new Node<string>("kolega");
    Node<string> *n3 = new Node<string>("witam");
    Node<string> *n4 = new Node<string>("cie");

    n1->next = n2;
    n2->previous = n1;
    n2->next = n3;
    n3->previous = n2;
    n3->next = n4;
    n4->previous = n3;

    printList(n1);
}