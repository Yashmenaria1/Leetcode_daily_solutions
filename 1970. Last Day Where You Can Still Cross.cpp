class Solution {
public:
    
    bool bfs(int time , vector<vector<int>>& cells, int &m , int &n){
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(int i=0;i<time;i++){
            grid[cells[i][0]-1][cells[i][1]-1] = 1;             
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) {
            if(grid[0][i]==0)
                q.push({0,i});
        }
        int ans = 1;
        int dx[4] = {0,0,-1,1};
        int dy[4] = {1,-1,0,0}; 
        while(!q.empty()) {
                auto top  = q.front();
                q.pop();
                int x = top.first , y = top.second; 
                if(x == m-1)
                    return 1; 
                for(int j=0;j<4;j++){
                    if(x+dx[j] <0 || y+dy[j] <0 || x+dx[j]>=m || y+dy[j]>=n || grid[x+dx[j]][y+dy[j]]) 
                        continue;
                    q.push({x+dx[j] , y+dy[j]}); 
                    grid[x+dx[j]][y+dy[j]] = 1;                    
                }
        }
        
        return false; 
    }
    
    int latestDayToCross(int m, int n, vector<vector<int>>& cells) {
        
        int low = 1 , high = m*n , ans =0;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(bfs(mid , cells , m ,n )) {
                ans = mid; 
                low = mid+1; 
            }
            else 
                high = mid-1;
        }
        return ans;
    }
};
