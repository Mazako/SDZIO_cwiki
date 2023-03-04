#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node* next;
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
void printList(Node<T>* firstNode);

template <class T>
Node<T>* search(Node<T>* firstNode, int index);

template <class T>
void addFirstNode(Node<T>* firstNode, Node<T>* newNode);

template <class T>
void addLastNode(Node<T>* firstNode, Node<T>*newNode);

template <class T>
void addAnyNode(Node<T>* firstNode, Node<T>* newNode, int index);

template <class T>
void removeNode(Node<T>* firstNode, int index);

void testPrintList();

void testSearch();

void testAddFirstNode();

void testAddLastnode();

void testAddAnyNode();

void testRemoveNode();

int main() {
    testPrintList();
    return 0;
}

template <class T>
void printList(Node<T>* firstNode) {
    while (firstNode) {
        cout << firstNode->data << " ";
        firstNode = firstNode->next;
    }
    cout << endl;
}

template <class T>
Node<T>* search(Node<T>* firstNode, int index) {
    
}


//EXPECTED OUTPUT: ciesc kolega witam cie
void testPrintList() {
    Node<string>* n1 = new Node<string>("ciesc");
    Node<string>* n2 = new Node<string>("kolega");
    Node<string>* n3 = new Node<string>("witam");
    Node<string>* n4 = new Node<string>("cie");

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    printList(n1);
}