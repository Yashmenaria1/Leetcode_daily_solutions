class Solution {
public:
    int maxFreq = 0, currFreq = 0, pre = INT_MIN;
    vector<int> res;

    vector<int> findMode(TreeNode *root){
        inorderTraversal(root);
        return res;
    }

    void inorderTraversal(TreeNode *root){
        if (root == NULL) return; 
        inorderTraversal(root->left);
        if (pre == root->val) currFreq++;
        else currFreq = 1;

        if (currFreq > maxFreq){
            res.clear();
            maxFreq = currFreq;
            res.push_back(root->val);
        }

        else if (currFreq == maxFreq){
            res.push_back(root->val);
        }

        pre = root->val; 
        inorderTraversal(root->right); 
    }
};
