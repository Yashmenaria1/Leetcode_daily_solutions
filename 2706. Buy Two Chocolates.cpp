class Solution {
public:
    int buyChoco(vector<int>& price, int money) {
        sort(price.begin(), price.end());
        return (money >= (price[0] + price[1])) ? money - (price[0] + price[1]) : money;   
    }
};
