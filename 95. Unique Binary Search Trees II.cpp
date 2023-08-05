class Solution{
public:
    vector<TreeNode*> helper(int s, int e){
        vector<TreeNode*> res;
        if (s > e){
            res.push_back(NULL);
            return res;
        }

        for (int i = s; i <= e; i++) {
            auto left = helper(s, i - 1);
            auto right = helper(i + 1, e);

            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(i);

                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        auto tree = helper(1, n);
        return tree;
    }
};
