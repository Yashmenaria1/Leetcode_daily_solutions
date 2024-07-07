class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numBottles>=numExchange){
            int emptyBottles = numBottles % numExchange;
            ans += numBottles / numExchange;
            numBottles /= numExchange;
            numBottles += emptyBottles;
        }
        return ans;
    }
};
