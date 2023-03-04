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
    testAddFirstNode();
    testAddLastnode();
    testAddAnyNode();
    testRemoveNode();
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
    Node<T> *currentNode = firstNode;
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

template <class T>
void addFirstNode(Node<T> *firstNode, Node<T> *newNode)
{
    newNode->next = firstNode;
}

template <class T>
void addLastNode(Node<T> *firstNode, Node<T> *newNode)
{
    Node<T> *currentNodePtr = firstNode;
    while (currentNodePtr->next != nullptr)
    {
        currentNodePtr = currentNodePtr->next;
    }
    currentNodePtr->next = newNode;
}

template <class T>
void addAnyNode(Node<T> *firstNode, Node<T> *newNode, int index)
{
    Node<T> *currentNode = firstNode;
    if (index == 0)
    {
        newNode->next = firstNode;
        return;
    }
    for (int i = 0; i < index - 1; i++)
    {
        currentNode = currentNode->next;
        if (currentNode == nullptr)
        {
            throw invalid_argument("Array index out of bound");
        }
    }
    if (currentNode->next == nullptr)
    {
        currentNode->next = newNode;
    }
    else
    {
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }
}

template <class T>
void removeNode(Node<T> *firstNode, int index)
{
    Node<T> *currentNode = firstNode;
    for (int i = 0; i < index - 1; i++)
    {
        currentNode = currentNode->next;
    }

    if (currentNode->next->next == nullptr)
    {
        currentNode->next = nullptr;
    }
    else
    {
        currentNode->next = currentNode->next->next;
    }
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

void testAddFirstNode()
{
    cout << "Add first node testing" << endl;
    Node<int> *firstNode = new Node<int>(1);
    Node<int> *n2 = new Node<int>(2);
    firstNode->next = n2;
    Node<int> *newFirstNode = new Node<int>(0);
    addFirstNode(firstNode, newFirstNode);
    bool test = search(newFirstNode, 2) == n2;
    printList(newFirstNode);
    if (test)
    {
        cout << "\t TEST PASSED" << endl;
    }
    else
    {
        cout << "\t TEST FAILED" << endl;
    }
}

void testAddLastnode()
{
    cout << "Add last node testing" << endl;
    Node<int> *firstNode = new Node<int>(1);
    Node<int> *n2 = new Node<int>(2);
    Node<int> *n3 = new Node<int>(3);
    addLastNode(firstNode, n2);
    addLastNode(firstNode, n3);
    printList(firstNode);
    bool test = search(firstNode, 2) == n3;
    if (test)
    {
        cout << "\t TEST PASSED" << endl;
    }
    else
    {
        cout << "\t TEST FAILED" << endl;
    }
}

void testAddAnyNode()
{
    cout << "Add node at any index testing" << endl;
    bool tests[4];
    Node<int> *firstNode = new Node<int>(1);
    Node<int> *n2 = new Node<int>(2);
    Node<int> *n3 = new Node<int>(3);
    Node<int> *n4 = new Node<int>(4);
    Node<int> *n5 = new Node<int>(5);
    Node<int> *n7 = new Node<int>(7);
    Node<int> *newFirstNode = new Node<int>(6);

    firstNode->next = n2;
    n2->next = n3;

    addAnyNode(firstNode, n4, 1);
    tests[0] = search(firstNode, 1) == n4;

    addAnyNode(firstNode, newFirstNode, 0);
    tests[1] = search(newFirstNode, 0) == newFirstNode;

    addAnyNode(newFirstNode, n5, 5);
    tests[2] = search(newFirstNode, 5) == n5 && n5->next == nullptr;

    try
    {
        addAnyNode(newFirstNode, n7, 7);
    }
    catch (invalid_argument &e)
    {
        tests[3] = true;
    }

    printList(newFirstNode);
    for (int i = 0; i < 4; i++)
    {
        if (tests[i])
        {
            cout << "\ttest " << i + 1 << ": GOOD" << endl;
        }
        else
        {
            cout << "\ttest " << i + 1 << ": BAD" << endl;
        }
    }
}

void testRemoveNode()
{
    cout << "Remove any node test" << endl;
    bool test[3];
    Node<int> *n1 = new Node(1);
    Node<int> *n2 = new Node(2);
    Node<int> *n3 = new Node(3);
    Node<int> *n4 = new Node(4);
    Node<int> *n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    removeNode(n1, 1);
    test[0] = search(n1, 1) == n3;
    printList(n1);

    removeNode(n1, 2);
    test[1] = search(n1, 2) == n5;
    printList(n1);
    
    removeNode(n1, 2);
    printList(n1);
    try
    {
        search(n1, 2);
    }
    catch (const invalid_argument &e)
    {
        test[2] = true;
    }

    for (int i = 0; i < 4; i++)
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