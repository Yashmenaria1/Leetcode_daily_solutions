class Solution {
public:
    string ans = "";
    void func(TreeNode* node, string tmp){
        
        tmp = (char)(node->val + 'a') + tmp;
        if(node->left == NULL && node->right == NULL ) {
            if(ans == "") ans = tmp;
            else{
                ans= min(ans, tmp);
            }
        }
        if(node->left) func(node->left, tmp);
        if(node->right) func(node->right, tmp);
    }
    string smallestFromLeaf(TreeNode* root) {
        
        if(!root) return ans;
        func(root, "");
        return ans;
    }
};
