class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool increase = true;
        bool decrease = true;
        for(int i = 0; i < A.size() - 1; i++) {
            if(A[i] > A[i+1]) increase = false;
            if(A[i] < A[i+1]) decrease = false;
            if(increase == false && decrease == false) return false;
        }
        return true;
    }
};

//Java Solution
// class Solution {
//     public boolean isMonotonic(int[] nums) {
//     int n= nums.length ,inc=0, dec=0;
//     for(int i=0;i+1<n;i++){
//         if(nums[i]<=nums[i+1]) inc++;
//         if(nums[i]>=nums[i+1]) dec++;
//     }
//     return inc+1==n || dec+1==n;
//   }
// }
