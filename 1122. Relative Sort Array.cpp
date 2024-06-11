class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for(auto& i : arr1){
            mp[i]++;
        }
        int pos = 0;
        for (auto j : arr2) {
            while(mp[j]-- > 0) arr1[pos++] = j;
        }
        for (auto it : mp) {
            while(it.second-- > 0) arr1[pos++] = it.first;
        }
        return arr1;
    }
};
