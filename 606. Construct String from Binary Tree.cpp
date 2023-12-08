class Solution {
public:
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        string str = to_string(root->val);
        if (root->left) 
            str += "(" + tree2str(root->left) + ")";
        if (root->right) {
            if (!root->left) str += "()";
            str += "(" + tree2str(root->right) + ")"; 
        }
        return str;
    }
};
