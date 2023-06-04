class Solution {
public:
    vector<int>friends;
 	
    int find(int i)
    {
        return friends[i]==i?i:find(friends[i]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        friends.resize(n);
        for(int i = 0; i < n; i++){
            friends[i] = i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    int x = find(i);
                    int y = find(j);
                    if(x != y)
                    {
                        friends[y] = x;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0;i < n ;i++)
        {
            if(friends[i]==i)
                ans++;
        }
        return ans;
    }
};
