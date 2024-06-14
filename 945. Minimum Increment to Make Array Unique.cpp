//TLE
//O(N^2)
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i <nums.size() - 1; i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i] == nums[j]){
                    nums[j] += 1;
                    count++;
                }
               
            }
        }
        return count;
    }
};

//passed all cases
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, need = 0;
        for (int num : nums) {
            if (num < need) {
                count += need - num;
            }
            need = max(num, need) + 1;
        }
        return count;
    }
};
