class Solution {
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int i=0,j=grid[0].size()-1;
        int count = 0,size=grid.size();
        
        while(i>=0 && i<grid.size() && j>=0 && j<grid[0].size()) 
        {
            if(grid[i][j]<0)
            {
                count = count+size; 
                j--; 
            }
            else
            {
            	i++;
            	size--;
            }
            
        }
        return count;
        
    }
};
