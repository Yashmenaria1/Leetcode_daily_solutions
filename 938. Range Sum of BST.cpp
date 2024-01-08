class Solution {
private:
     int ans = 0;
public:
     int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root , low , high);
        return ans;
    }
    
private:
     void dfs(TreeNode* node , int L , int H){
        if(node != NULL){
            if( L <= node->val && node->val <= H)
                ans += node->val;
            if(L < node->val)
                dfs(node->left , L , H);
            if(node->val < H)
                dfs(node->right , L , H);
        }
    }
};
