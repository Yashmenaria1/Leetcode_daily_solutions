class Solution {
public:
    static bool compare(int a, int b){
        bitset<32> b1(a);
        bitset<32> b2(b);
        if(b1.count() != b2.count()){
            return b1.count() < b2.count();
        }
        else  return a < b;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};
