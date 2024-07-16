class Solution {
public:
    bool search(TreeNode* root, int des, string& s){
        if(!root) return false;
        if(root->val == des) return true;
        bool left = search(root->left, des, s+='L');
        if(left) return true;
        s.pop_back();
        bool right = search(root->right, des, s+='R');
        if(right) return true;
        s.pop_back();
        return false;
    }
    TreeNode* lca(TreeNode* root ,int n1 ,int n2){
       if(!root) return NULL;
       if(root->val==n1 || root->val==n2) return root;
       
       TreeNode* left = lca(root->left, n1, n2);
       TreeNode* right = lca(root->right, n1, n2);
       
       if(left!=NULL && right!=NULL) return root;
       if(left) return left;
       if(right) return right;
       return NULL; 
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* temp = lca(root,startValue,destValue);
        
        string s1, s2;
        search(temp, startValue, s1);
        search(temp, destValue, s2);
        for(auto &it:s1){
            it = 'U';
        }
        return s1+s2;
    }
};
