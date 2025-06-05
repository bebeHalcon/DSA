int singleChildHelper(BSTNode* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftChild = singleChildHelper(node -> left);
    int rightChild = singleChildHelper(node -> right);

    if ((node -> left != nullptr && node -> right == nullptr) ||
        (node -> left == nullptr && node -> right != nullptr)) {
        return leftChild + rightChild + 1;
    } else {
        return leftChild + rightChild;
    }
}

int singleChild(BSTNode* root) {
    return singleChildHelper(root);
}