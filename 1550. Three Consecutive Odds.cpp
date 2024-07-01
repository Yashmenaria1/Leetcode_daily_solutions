class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        vector<int> ans;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]%2 != 0){
                ans.push_back(arr[i]);
                if(ans.size() >=3 ){
                    break;
                }
            }
            else{
                ans.clear();
            }
        }
        return ans.size() >= 3;
    }
};
