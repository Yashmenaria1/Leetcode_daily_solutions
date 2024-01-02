class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n + 10);
        vector<vector<int>> res;
        for(int num : nums){
            if(res.size() <= count[num])
                res.push_back({});
            res[count[num]++].push_back(num);
        }
        return res;
    }
};
