class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int res = 0;
        map<vector<int>, int> m;
        for (int i = 0; i < grid.size(); i++)
            m[grid[i]]++;
        
        for (int i = 0; i < grid[0].size(); i++)
        {
            vector<int> v;
            for (int j = 0; j < grid.size(); j++)
                v.push_back(grid[j][i]);
            res += m[v];
        }
        return res;
    }
};
