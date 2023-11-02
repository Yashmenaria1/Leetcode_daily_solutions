class Solution {
public: 
    array<int, 3> dfs(TreeNode* n) {
    if (n == nullptr)
        return {0, 0, 0};
    auto p1 = dfs(n->left), p2 = dfs(n->right);
    int sum = p1[0] + p2[0] + n->val, count = 1 + p1[1] + p2[1];
    return {sum, count, p1[2] + p2[2] + (n->val == sum / count)};
    }

    int averageOfSubtree(TreeNode* root) {
    return dfs(root)[2];
    }
};
