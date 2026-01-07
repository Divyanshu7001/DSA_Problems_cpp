/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long SUM = 0, maxProd = 0;
    int M = 1e9 + 7;
    int totalSum(TreeNode* root) {
        if (!root)
            return 0;

        int leftTreeSum = 0, rightTreeSum = 0;
        if (root->left)
            leftTreeSum = totalSum(root->left);
        if (root->right)
            rightTreeSum = totalSum(root->right);
        int sum = root->val+leftTreeSum + rightTreeSum;

        maxProd = max(maxProd, (SUM-sum)*sum);

        return sum;
    }

    int maxProduct(TreeNode* root) {
        if (!root)
            return 0;

        SUM = totalSum(root);
        totalSum(root);

        return maxProd % M;
    }
};