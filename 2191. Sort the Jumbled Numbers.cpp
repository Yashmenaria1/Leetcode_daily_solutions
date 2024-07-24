class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int na = nums.size();
        vector<pair<int, int>> mpp(na);
        vector<int> ans;
        for(int i = 0; i<nums.size(); i++){
            int n = nums[i];
            int num = n==0?mapping[0]:0;
            int place = 1;
            while(n){
                int digit = n%10;
                num += mapping[digit]*place;
                n/=10;
                place *= 10;
            }
            mpp[i] = {num, i};
        }
        sort(mpp.begin(), mpp.end());
        for(auto m:mpp){
            ans.push_back(nums[m.second]);
        }
        return ans;
    }
};
