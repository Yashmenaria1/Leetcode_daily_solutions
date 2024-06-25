class Solution {
public:
    void revInOrder(TreeNode* root, int& sum){
        if(!root) return;
        revInOrder(root->right, sum);
        sum += root->val;
        root->val = sum;
        revInOrder(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        revInOrder(root, sum);
        return root;
    }
};
