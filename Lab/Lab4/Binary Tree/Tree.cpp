// STUDENT ANSWER BEGIN
// You can define other functions here to help you.
int getHeight() {
    return calculateHeight(root);
}

string preOrder() {
    stringstream ss;
    preOrderTraversal(root, ss);
    return ss.str();
}

string inOrder() {
    stringstream ss;
    inOrderTraversal(root, ss);
    return ss.str();
}

string postOrder() {
    stringstream ss;
    postOrderTraversal(root, ss);
    return ss.str();
}

int calculateHeight(Node* node) {
    if (node == nullptr) return 0;
    
    int leftHeight = calculateHeight(node -> pLeft);
    int rightHeight = calculateHeight(node -> pRight);

    return 1 + max(leftHeight, rightHeight);
}

void preOrderTraversal(Node* node, stringstream& ss) {
    if (node == nullptr) return;

    ss << node -> value << " ";
    preOrderTraversal(node -> pLeft, ss);
    preOrderTraversal(node -> pRight, ss);
}

void inOrderTraversal(Node* node, stringstream& ss) {
    if (node == nullptr) return;

    inOrderTraversal(node -> pLeft, ss);
    ss << node -> value << " ";
    inOrderTraversal(node -> pRight, ss);
}

void postOrderTraversal(Node* node, stringstream& ss) {
    if (node == nullptr) return;

    postOrderTraversal(node -> pLeft, ss);
    postOrderTraversal(node -> pRight, ss);
    ss << node -> value << " ";
}

// STUDENT ANSWER END