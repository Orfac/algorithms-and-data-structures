typedef struct Node{
    Node* left;
    Node* right;
    int value;
} Node;

int findDepth(Node* node){
    int depth = 1;
    int depthLeft = 0;
    if (node->left != nullptr) depthLeft = findDepth(node->left);
    int depthRight = 0;
    if (node->right != nullptr) depthRight = findDepth(node->right);
    int maxVal = max(depthLeft,depthRight);
    return depth + maxVal;
}

int main() {
    int n;
    cin >> n;
    Node *nodes = new Node[n];
    for (int i = 0; i < n; ++i) {
        nodes[i].right = nullptr;
        nodes[i].left = nullptr;
    }
    for (int i = 0; i < n; ++i) {
        int k,l,r;
        cin >> k >> l >> r;
        nodes[i].value = k;
        if (l != 0) nodes[i].left = &(nodes[l - 1]);
        if (r != 0) nodes[i].right = &(nodes[r - 1]);
    }
    cout << findDepth(&(nodes[0]));
    return 0;
}

