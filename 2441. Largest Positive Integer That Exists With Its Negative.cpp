//O(N^2) solution
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi = -1;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(i!=j && nums[i] == -nums[j]) {
                    maxi = max(maxi, abs(nums[j]));
                }
            }
        }
        return maxi;
    }
};

// O(n) Solution
class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> seen;
        int maxi = -1;
        for (int num : nums) {
            if (seen.count(-num)) {
                maxi = max(maxi, abs(num));
            }
            seen.insert(num);
        }
        return maxi;
    }
};
