class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // if(hand.size()%groupSize*3 != 0) return false;
        map<int, int> m;
        for(int i : hand) m[i]++;
        for(auto it : m){
            if(it.second > 0){
                for(int i = 0; i<groupSize; i++){
                    if(m[it.first + i] < it.second){
                        return false;
                    }
                    m[it.first + i] -= it.second;
                }
            }
        }
        return true;
    }
};
