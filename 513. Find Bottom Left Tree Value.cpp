class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*, list<TreeNode*>> q;
        q.push(root);
        TreeNode* leftmost = nullptr;
        while (!q.empty()) {
            leftmost = q.front();
            q.pop();
            if (leftmost->right != nullptr) {
                q.push(leftmost->right);
            }
            if (leftmost->left != nullptr) {
                q.push(leftmost->left);
            }
        }
        return leftmost->val;
    }
};
