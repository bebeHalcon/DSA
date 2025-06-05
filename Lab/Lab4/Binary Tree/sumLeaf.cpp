int sumOfLeafsHelper(Node *node) {
    if (!node) return 0;

    if (!node -> pLeft && !node -> pRight) return node -> value;

    int leftSum = sumOfLeafsHelper(node -> pLeft);
    int rightSum = sumOfLeafsHelper(node -> pRight);

    return leftSum + rightSum;
}
int sumOfLeafs(){
    //TODO
    return sumOfLeafsHelper(root);

}