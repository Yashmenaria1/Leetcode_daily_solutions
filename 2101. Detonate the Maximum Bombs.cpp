class Solution {
public:
  int maximumDetonation(vector<vector<int>>& b) {
    int n = b.size(), answer = 1;
    vector<vector<int>>g(n);
    
    for(int i = 0; i != n; i++){
      long R = (long)b[i][2] * b[i][2];
      for(int j = i+1; j != n; j++){
        long dx = b[j][0] - b[i][0], dy = b[j][1] - b[i][1];
        long r = (long)b[j][2] * b[j][2];
        long d = dx*dx + dy*dy;
        if( d <= R) g[i].push_back(j);
        if( d <= r) g[j].push_back(i);
      }
    }
    
    for(int i = 0; i != n && answer != n; i++){
      vector<int>visitedBombs;
      visitedBombs.clear();
      visitedBombs.resize(n,0);
      queue<int>m;
      m.push(i);
    
      int k = 0;
      while(!m.empty()){
        int t = m.front(); m.pop();
        if(visitedBombs[t]) continue;
        visitedBombs[t] = 1, k++;
          
        for(auto next: g[t]) if(visitedBombs[next] == 0) m.push(next);
      }
      answer = max<int>(answer, k);
    }
    
    return answer;
  }
};
