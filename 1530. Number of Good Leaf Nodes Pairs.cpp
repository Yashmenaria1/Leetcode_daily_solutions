class Solution {
public:
    int ans = 0;
    vector<int>dfs(TreeNode* root, int distance){
        vector<int> v;
        if(!root) return {};
        if(!root->left && !root->right){
            return {1};
        }
        auto left = dfs(root->left, distance);
        auto right = dfs(root->right, distance);

        for(auto x:left){
            for(auto y:right){
                if(x+y <= distance){
                    ans++;
                }
            }
        }
        for(auto x:left) v.push_back(x+1);
        for(auto x:right) v.push_back(x+1);
        return v;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return ans;
    }
};
