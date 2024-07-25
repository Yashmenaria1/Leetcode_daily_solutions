class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high){
        vector<int> v;
        int left = low, right = mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                v.push_back(nums[left]);
                left++;
            }
            else{
                v.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            v.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            v.push_back(nums[right]);
            right++;
        }
        for(int i = low; i<=high; i++){
            nums[i] = v[i-low];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if(low == high) return;
        int mid = (high+low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
