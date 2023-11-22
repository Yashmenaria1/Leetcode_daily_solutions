class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int maxSum = 0, size = 0, index = 0;
        
        vector<vector<int>> temp(1001); 
        
        for (int i = 0; i < nums.size(); i++) {
            size += nums[i].size();
            for (int j = 0; j < nums[i].size(); j++) {
                int sum = i + j;
                
                if (sum >= temp.size()) {
                    temp.resize(sum + 1);
                }
                temp[sum].push_back(nums[i][j]);
                maxSum = max(maxSum, sum);
            }
        }
        
        vector<int> res(size);
        for (int i = 0; i <= maxSum; i++) {
            vector<int>& curr = temp[i];
            for (int j = curr.size() - 1; j >= 0; j--) {
                res[index++] = curr[j];
            }
        }
        return res;
    }
};
