class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int res = 0;
        int k = 0;
        int m_i = -1, g_i = -1, p_i = -1;
        for(int i = 1; i < travel.size(); i++) travel[i] = travel[i-1] + travel[i];
        for(auto x : garbage){
            for(auto c : x){
                res++;
                if(c == 'M') m_i = k;
                if(c == 'P') p_i = k;
                if(c == 'G') g_i = k;
            }
            k++;
        }
        res += ((m_i > 0) ? travel[m_i - 1] : 0);
        res += ((p_i > 0) ? travel[p_i - 1] : 0);
        res += ((g_i > 0) ? travel[g_i - 1] : 0);
        return res;
    }
};
