BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
    if (root == nullptr) {
        return nullptr;
    }

    root -> left = subtreeWithRange(root -> left, lo, hi);
    root -> right = subtreeWithRange(root -> right, lo, hi);

    if (root -> val < lo) {
        BSTNode* rightChild = root -> right;
        delete root;
        return rightChild;
    } else if (root -> val > hi) {
        BSTNode* leftChild = root -> left;
        delete root;
        return leftChild;
    }

    return root;
}