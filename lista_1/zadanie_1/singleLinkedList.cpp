#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
void printList(Node<T> *firstNode);

template <class T>
Node<T> *search(Node<T> *firstNode, int index);

template <class T>
void addFirstNode(Node<T> *firstNode, Node<T> *newNode);

template <class T>
void addLastNode(Node<T> *firstNode, Node<T> *newNode);

template <class T>
void addAnyNode(Node<T> *firstNode, Node<T> *newNode, int index);

template <class T>
void removeNode(Node<T> *firstNode, int index);

void testPrintList();

void testSearch();

void testAddFirstNode();

void testAddLastnode();

void testAddAnyNode();

void testRemoveNode();

int main()
{
    testPrintList();
    testSearch();
    return 0;
}

template <class T>
void printList(Node<T> *firstNode)
{
    Node<T> *currentNode = firstNode;
    while (currentNode)
    {
        cout << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
}

template <class T>
Node<T> *search(Node<T> *firstNode, int index)
{
    Node<T>* currentNode = firstNode;
    for (int i = 1; i <= index; i++)
    {
        currentNode = currentNode->next;
        if (currentNode == nullptr)
        {
            throw invalid_argument("List index out of range");
        }
    }
    return currentNode;
}

// EXPECTED OUTPUT: ciesc kolega witam cie
void testPrintList()
{
    Node<string> *n1 = new Node<string>("ciesc");
    Node<string> *n2 = new Node<string>("kolega");
    Node<string> *n3 = new Node<string>("witam");
    Node<string> *n4 = new Node<string>("cie");

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printList(n1);
}

void testSearch()
{
    cout << "Search testing:" << endl;
    bool test[5];
    Node<int> *n1 = new Node<int>(1);
    Node<int> *n2 = new Node<int>(2);
    Node<int> *n3 = new Node<int>(3);
    Node<int> *n4 = new Node<int>(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    test[0] = search(n1, 0)->data == 1;
    test[1] = search(n1, 1)->data == 2;
    test[2] = search(n1, 2)->data == 3;
    test[3] = search(n1, 3)->data == 4;
    try
    {
        search(n1, 4);
    }
    catch (invalid_argument &e)
    {
        test[4] = true;
    }
    for (int i = 0; i < 5; i++)
    {
        if (test[i])
        {
            cout << "\ttest " << i + 1 << ": GOOD" << endl;
        }
        else
        {
            cout << "\ttest " << i + 1 << ": BAD" << endl;
        }
    }
}