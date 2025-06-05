int rangeCount(BTNode *root, int lo, int hi) {
    if (root == nullptr) {
        return 0;
    }

    int count = 0;

    if (lo <= root -> val) {
        count += rangeCount(root -> left, lo, hi);
    }

    // Check if the current node's value is within the range
    if (lo <= root -> val && root -> val <= hi) {
        count++;
    }

    if (hi >= root -> val) {
        count += rangeCount(root -> right, lo, hi);
    }

    return count;
}