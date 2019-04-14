#include <iostream>

using namespace std;

#include "edx-io.hpp"
#define cin io
#define cout io


typedef struct Node{
    Node* left;
    Node* right;
    Node* parent;
    int height;
    int value;
} Node;

int updateHeight(Node* node){
    int depth = 1;
    int depthLeft = 0;
    if (node->left != nullptr) depthLeft = updateHeight(node->left);
    int depthRight = 0;
    if (node->right != nullptr) depthRight = updateHeight(node->right);
    node->height = depth + max(depthLeft,depthRight);
    return node->height;
}

int getBalance(Node* node){
    int heightRight = 0;
    if (node->right != nullptr) heightRight = node->right->height;
    int heightLeft = 0;
    if (node->left != nullptr) heightLeft = node->left->height;
    return  heightRight - heightLeft;
}

int main() {
    int n;
    cin >> n;
    Node *nodes = new Node[n];
    for (int i = 0; i < n; ++i) {
        nodes[i].right = nullptr;
        nodes[i].left = nullptr;
        nodes[i].parent = nullptr;
        nodes[i].height = 0;
    }
    for (int i = 0; i < n; ++i) {
        int k,l,r;
        cin >> k >> l >> r;
        nodes[i].value = k;
        if (l != 0){
            nodes[i].left = &(nodes[l - 1]);
        }
        if (r != 0){
            nodes[i].right = &(nodes[r - 1]);
        }
    }
    updateHeight(&nodes[0]);

    for (int i = 0; i < n; ++i) {
        cout << getBalance(&nodes[i]) << '\n';
    }

    return 0;
}
