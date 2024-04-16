class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int currDepth = 1;
        
        while (!q.empty() && currDepth < depth - 1) {
            int size = q.size();
            while (size--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            currDepth++;
        }
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            TreeNode* leftNode = new TreeNode(val);
            leftNode->left = curr->left;
            curr->left = leftNode;
            TreeNode* rightNode = new TreeNode(val);
            rightNode->right = curr->right;
            curr->right = rightNode;
        } 
        return root;
    }
};
