class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st;
        vector<int> vp;
        int size= nums.size();
        for(int i=0; i< nums.size(); i++){
            st.insert(nums[i]);
        }
        for(int value: st){
            vp.push_back(value);
        }
        int n = vp.size();
        int leftptr =0;
        int rightptr =0;
        int maxi =0;
        for (int leftptr =0; leftptr< n; leftptr++){
            while(rightptr< n and vp[rightptr]- vp[leftptr]<= size-1){
                rightptr++;
            }
            maxi = max(maxi, rightptr - leftptr);
        }
        return size - maxi;

    }
};
