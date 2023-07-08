class Solution {
public:
    long long putMarbles(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        nums[i]+=nums[i+1];
        nums.pop_back();
        sort(nums.begin(), nums.end());
        long long ans=0;
        for(int i=0;i<k-1;i++)
        ans+=nums[n-i-2]-nums[i];
        return ans;
    }
};
