#include <iostream>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node *parent;
};

void preorder(Node *p)
{
    if (p == nullptr)
    {
        return;
    }
    cout << p->key;
    preorder(p->left);
    preorder(p->right);
}

void inorder(Node *p)
{
    if (p == nullptr)
        return;
    inorder(p->left);
    cout << p->key;
    inorder(p->right);
}

void postorder(Node *p)
{
    if (p == nullptr)
        return;
    postorder(p->left);
    postorder(p->right);
    cout << p->key;
}

Node *search(Node *node, int key)
{
    if (node == nullptr || node->key == key)
        return node;
    if (key > node->key)
        return search(node->right, key);
    return search(node->left, key);
}

Node* searchMax(Node* node)
{
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

Node* searchMin(Node* node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

void insertNode(Node** root ,Node* node)
{
    if (*root == nullptr)
    {
        *root = node;
        return;
    }
    Node* parent = nullptr;
    Node* nodePtr = *root;
    while (nodePtr != nullptr)
    {
        parent = nodePtr;
        if (node->key < nodePtr->key)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }
    node->parent = parent;
    if (node->key < parent->key)
        parent->left = node;
    else
        parent->right = node;
}