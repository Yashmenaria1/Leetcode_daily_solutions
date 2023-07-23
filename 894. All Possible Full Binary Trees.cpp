class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if((n&1) == 0)return {}; 
        if(n == 1)return {new TreeNode()};
		
        vector<TreeNode*>res;
		
        for(int i = 1; i < n-1;i+=2){
		
            vector<TreeNode*>left = allPossibleFBT(i);
            vector<TreeNode*>right = allPossibleFBT(n-i-1);
			
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(); 
                    root->left = l; 
                    root->right = r; 
                    res.push_back(root);
                }
            }
        }
		
        return res;
    }
};
