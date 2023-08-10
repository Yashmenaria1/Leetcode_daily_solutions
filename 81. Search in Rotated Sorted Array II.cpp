class Solution {
public:
    bool search(vector<int>& nums, int target)
    {
        int start = 0, end = nums.size() - 1, mid;
        while(start <= end)
        {
            mid = start + (end - start)/2;
            if(target == nums[mid])
                return true;
            
            if(nums[start] == nums[mid] and nums[mid] == nums[end])
            {
                start++; end--;
                continue;
            }
            
            if(nums[start] <= nums[mid])              
            {
                if(nums[start] <= target and target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            else                                  
            {
                if(nums[mid] < target and target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        return false;
    }
};
