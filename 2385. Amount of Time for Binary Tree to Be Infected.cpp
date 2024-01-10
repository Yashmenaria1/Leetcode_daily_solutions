class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        vector<int> res(1,0);
        dfs(root, start, res);
        return res[0];
    }
    
    int dfs(TreeNode* root, int start, vector<int>& res) {
        if (root == nullptr) return 0;
        int left = dfs(root->left, start, res);        
        int right = dfs(root->right, start, res);

        if (root->val == start) {
            int temp = max(abs(left), abs(right));
            res[0] = max(res[0], temp);
            return 0;
        }
        if (left > 0 || (root->left != nullptr && root->left->val == start)) {
            int sum = left + abs(right) + 1;
            res[0] = max(res[0], sum);
            return left + 1;
        } else if (right > 0 || (root->right != nullptr && root->right->val == start)) {
            int sum = right + abs(left) + 1;
            res[0] = max(res[0], sum);
            return right + 1;
        } 
        
        int sum = max(abs(left), abs(right));
        return -sum - 1;
    }
};
