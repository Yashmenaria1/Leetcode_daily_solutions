class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> temp(n);
        for(int i = 0; i < n; i++){
            temp[i] = ceil ((1.0*dist[i])/speed[i]);
        }
		
        sort(temp.begin(), temp.end()); 
        int time = 1;
		
        for(int i = 0;i < n; i++){
            if(time > temp[i]){  
                return i;
            }
            time++;
        }
        return n;  
    }
};
