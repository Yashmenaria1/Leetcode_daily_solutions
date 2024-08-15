class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mp;
        for(int i = 0; i<bills.size(); i++){
            if(bills[i] == 5){
                mp[bills[i]]++;
            }
            else if(bills[i] == 10){
                if(mp.find(5) != mp.end() && mp[5]>0){
                    mp[5]--;
                    mp[bills[i]]++;
                }
                else{
                    return false;
                }
            }
            else{
                if(mp.find(5) != mp.end() && mp[5]>0 && mp.find(10) != mp.end() && mp[10]>0){
                    mp[5]--;
                    mp[10]--;
                    mp[bills[i]]++;
                }
                else if(mp.find(5) != mp.end() && mp[5]>=3){
                    mp[5] -= 3;
                    mp[bills[i]]++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
