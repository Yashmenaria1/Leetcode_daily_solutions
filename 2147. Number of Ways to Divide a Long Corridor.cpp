class Solution {
public:
        int numberOfWays(string corridor) {
        long no_of_Ways = 1, j = 0, seats = 0, mod = 1e9 + 7;
        for (int i = 0; i < corridor.size(); ++i) {
            if (corridor[i] == 'S') {
                if (++seats > 2 && seats % 2 == 1)
                    no_of_Ways = no_of_Ways * (i - j) % mod;
                j = i;
            }
        }
        return seats % 2 == 0 && seats > 0 ? no_of_Ways : 0;
    }
};
