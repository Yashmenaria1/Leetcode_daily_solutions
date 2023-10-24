class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> maximum;
        find(root, 0, maximum);
        return maximum;
    }

private:
    void find(TreeNode* node, int row, vector<int>& maximum) {
        if (!node) {
            return;
        }

        if (row >= maximum.size()) {
            maximum.push_back(node->val);
        }
        else {
            maximum[row] = max(maximum[row], node->val);
        }

        find(node->left, row + 1, maximum);
        find(node->right, row + 1, maximum);
    }
};
