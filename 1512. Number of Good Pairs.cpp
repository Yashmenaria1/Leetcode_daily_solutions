class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        map<int , int> count;
        for(int num: nums){
            ans += count[num]++;
        }
        return ans;
    }
};

//JAVA solution
// class Solution {
//     public int numIdenticalPairs(int[] nums) {
//         int ans = 0, count[] = new int[101];
//         for (int num : nums){
//             ans += count[num]++;
//         }
//         return ans;
//     }
// }
