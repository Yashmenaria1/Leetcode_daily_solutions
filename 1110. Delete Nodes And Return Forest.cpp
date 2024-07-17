class Solution {
public:
    vector<TreeNode*> ans;
    unordered_set<int> s;
    void postOrder(TreeNode* &root){
        if(root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        if(s.find(root->val) != s.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            root = NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i = 0; i<to_delete.size(); i++){
            s.insert(to_delete[i]);
        }
        postOrder(root);
        if(root){
            ans.push_back(root);
        }
        return ans;
    }
};
