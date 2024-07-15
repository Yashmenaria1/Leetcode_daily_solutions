class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> children;

        for (const auto& d : descriptions) {
            children.insert(d[1]);
            if (mp.find(d[0]) == mp.end())  
                mp[d[0]] = new TreeNode(d[0]);

            if (mp.find(d[1]) == mp.end())
                mp[d[1]] = new TreeNode(d[1]);

            if (d[2] == 1)
                mp[d[0]]->left = mp[d[1]];
            else
                mp[d[0]]->right = mp[d[1]];
        }

        for (const auto& m : mp) {
            if (children.find(m.first) == children.end())
                return m.second;
        }

        return nullptr;
    }
};
