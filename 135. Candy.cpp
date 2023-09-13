class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>begin(n, 1), end(n, 1);
        for(int i = 1; i < n; i++)
            if(ratings[i] > ratings[i-1]) begin[i] = begin[i-1]+1;
              
        for(int i = n-2; i >= 0; i--)
            if(ratings[i] > ratings[i+1]) end[i] = end[i+1]+1;
        
        int res = 0;
        for(int i = 0; i < n; i++)
            res += max(begin[i], end[i]);
        
        return res;            
    }
};
