class Solution {
 public:
  int firstOcc(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end - start)/2;
        int y = -1;
        while(start <= end){
            
        if (nums[mid] == target){
            y = mid;
            end = mid-1;
             
        }
        else if(nums[mid] < target){
           start = mid + 1;
        } 
        else if ( nums[mid] > target){
            end = mid - 1;

        }
        mid=(start + end)/2;
        
        } 
       return y;
  }
  
   int lastOcc(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end - start)/2;
        int y=-1;
        while(start <= end){
            
        if (nums[mid] == target){
            y=mid;
            start = mid+1;
             
        }
        else if(nums[mid]<target){
           start = mid+1;
        } 
        else if ( nums[mid]>target){
            end = mid-1;

        }
        mid = start + (end - start)/2;
        
        } 
        return y; 
   }    

 
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOcc(nums,target),lastOcc(nums,target)};
    }
};
