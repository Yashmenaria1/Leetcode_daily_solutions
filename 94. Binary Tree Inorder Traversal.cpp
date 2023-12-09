class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        inorderTry(root);
        return ans;
    }
    void inorderTry(TreeNode* root){
        if(root == NULL) return;
        inorderTry(root->left);
        ans.push_back(root->val);
        inorderTry(root->right);
    }
};
