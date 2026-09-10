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
    using pp = pair<int, int>;
    int res = 0;
    pp dfs(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        int count = 1 + left.second + right.second;
        int sum = (root->val + left.first + right.first);
        if (sum/count == root->val)
            res++;

        return {sum, count};
    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};