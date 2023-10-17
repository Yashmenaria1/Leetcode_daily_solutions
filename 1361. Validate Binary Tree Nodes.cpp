class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
      vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(int i=0;i<left.size();i++)
        {
            if(left[i]!=-1)
            {
                adj[i].push_back(left[i]);
                ind[left[i]]++;
            }
        }
        for(int i=0;i<right.size();i++)
        {
           if(right[i]!=-1)
           {
               adj[i].push_back(right[i]);
               ind[right[i]]++;
           }
        }
       vector<int> vis(n,0);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
                break;
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(vis[node]!=0)return false;
            vis[node] =1;
            for(auto it:adj[node])
            {
                
                    q.push(it);
                
            }
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)return false;
        }
        return true;
    }
};
