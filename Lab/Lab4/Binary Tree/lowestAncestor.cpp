int lowestAncestor(BTNode* root, int a, int b) {
    if (root == NULL) {
        return -1;
    }

    if (root -> val == a || root -> val == b) {
        return root -> val;
    }

    int leftAncestor = lowestAncestor(root -> left, a, b);
    int rightAncestor = lowestAncestor(root -> right, a, b);

    if (leftAncestor != -1 && rightAncestor != -1) {
        return root -> val;
    }

    return (leftAncestor != -1) ? leftAncestor : rightAncestor;
}