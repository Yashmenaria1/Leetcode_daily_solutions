class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        for (int i : nums) {
            if (i % 2 == 0) {
                result.push_back(i);
            }
        }
        for (int j : nums) {
            if (j % 2 != 0) {
                result.push_back(j);
            }
        }
        return result;
    }
};

// In Java
// public class Solution {
//     public int[] sortArrayByParity(int[] nums) {
//         int[] result = new int[nums.length];
//         int evenIndex = 0;
//         int oddIndex = nums.length - 1;
        
//         for (int num : nums) {
//             if (num % 2 == 0) {
//                 result[evenIndex] = num;
//                 evenIndex++;
//             } else {
//                 result[oddIndex] = num;
//                 oddIndex--;
//             }
//         }
//         return result;
//     }
// }
