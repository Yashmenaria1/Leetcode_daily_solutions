class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        res += abs(l) + abs(r);
        return root->val + l + r - 1;
    }
};
