class Solution {
    int maxi = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return maxi;
    }
    
private:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        maxi = max(maxi, left + right);
        return max(left, right) + 1;
    }
};
