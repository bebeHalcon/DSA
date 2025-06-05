int kthSmallestHelper(BSTNode* root, int& k) {
    if (root == nullptr) {
        return -1;
    }

    int leftValue = kthSmallestHelper(root -> left, k);

    if (k == 0) {
        return leftValue;
    }

    if (--k == 0) {
        return root -> val;
    }

    return kthSmallestHelper(root -> right, k);
}

int kthSmallest(BSTNode* root, int k) {
    return kthSmallestHelper(root, k);
}