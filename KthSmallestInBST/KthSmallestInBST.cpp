// KthSmallestInBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>

class Node
{
public:
    Node* left;
    Node* right;
    int data;

    Node(int d)
        : data(d)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

Node* ArrayToTree(const std::vector<int>& v)
{
    if (v.size() == 0)
        return nullptr;
    Node* root = new Node(v[0]);
    std::queue<Node*> q;
    q.push(root);
    bool l = true;
    for (size_t i = 1; i < v.size(); ++i, l = !l)
    {
        Node* pNode = q.front();
        if (!l)
            q.pop();
        if (v[i] != -1)
        {
            if (l)
            {
                pNode->left = new Node(v[i]);
                q.push(pNode->left);
            }
            else
            {
                pNode->right = new Node(v[i]);
                q.push(pNode->right);
            }
        }
    }

    return root;
}

void FreeTree(Node* pNode)
{
    if (pNode == nullptr)
        return;

    FreeTree(pNode->left);
    FreeTree(pNode->right);

    delete pNode;
}

Node* KthSmallest(Node* pNode, int k, int& n)
{
    if (pNode == nullptr)
        return nullptr;

    Node* p = KthSmallest(pNode->left, k, n);
    if (p != nullptr)
        return p;
    ++n;
    if (n == k)
        return pNode;
    return KthSmallest(pNode->right, k, n);
}

int FindKthSmallest(Node* root, int k)
{
    int n = 0;
    Node* pNode = KthSmallest(root, k, n);
    if (pNode != nullptr)
        return pNode->data;

    return -1;
}

int main()
{
    while (true)
    {
        std::cout << "Number of nodes in BST: ";
        int count = 0;
        std::cin >> count;
        if (count == 0)
            break;

        std::cout << "The nodes: ";
        std::vector<int> v(count, 0);
        for (int i = 0; i < count; ++i)
        {
            std::cin >> v[i];
        }

        Node* pRoot = ArrayToTree(v);

        std::cout << "Number k: ";
        int k = 0;
        std::cin >> k;

        std::cout << "Kth largest in BST is " << FindKthSmallest(pRoot, k) << std::endl;

        FreeTree(pRoot);
    }
}
