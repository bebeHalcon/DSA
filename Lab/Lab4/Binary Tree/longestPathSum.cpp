void sumOfLongRootToLeafPath(BTNode* root, int sum, int len, int& maxLen, int& maxSum) {
    if (!root) {
        if (maxLen < len) {
            maxLen = len;
            maxSum = sum;
        } else if (maxLen == len && maxSum < sum)
            maxSum = sum;
        return;
    }
 
    sumOfLongRootToLeafPath(root -> left, sum + root -> val, len + 1, maxLen, maxSum);
 
    sumOfLongRootToLeafPath(root -> right, sum + root -> val,len + 1, maxLen, maxSum);
}

int longestPathSum(BTNode* root) {
    if (!root) return 0;
 
    int maxSum = -9999999, maxLen = 0;

    sumOfLongRootToLeafPath(root, 0, 0, maxLen, maxSum);
 
    return maxSum;
}