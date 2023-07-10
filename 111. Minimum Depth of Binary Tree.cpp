class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while (!q.empty()) {
            int size = q.size();
            depth++;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->left == NULL && node->right == NULL)
                    return depth;
                
                if (node->left)
                    q.push(node->left);
                
                if (node->right)
                    q.push(node->right);
            }
        }
        
        return 0;
    }
};
