class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == 1){
                k++;
            }
        }
        if(k == 0) return 0;
        vector<int> v = nums;
        v.insert(v.end(), nums.begin(), nums.end());
        int ones = 0, maxOnes = 0;
        for(int i = 0; i<k; i++){
            if(v[i] == 1) ones++;
        }
        maxOnes = ones;
        for(int i = k; i<v.size(); i++){
            if(v[i] == 1) ones++;
            if(v[i-k] == 1) ones--;
            maxOnes = max(maxOnes, ones);
        }
        return k-maxOnes;
    }
};
