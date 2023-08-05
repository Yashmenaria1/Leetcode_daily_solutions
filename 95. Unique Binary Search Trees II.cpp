class Solution {
public:
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> ans;
        if(start > end){
            ans.push_back(NULL);
            return ans;
        }
        
        for(int i = start; i <= end; i++){
            auto left = helper(start, i - 1);
            auto right = helper(i + 1, end);
            
            for(auto l : left){
                for(auto r : right){
                    TreeNode* root = new TreeNode(i);
                    
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        auto h = helper(1, n);
        return h;
    }
};
