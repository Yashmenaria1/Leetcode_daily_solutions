class Solution {
public:
    int dp[101][202];
    int recur(int curr_Ind,int Max_Piles,vector<int>&piles){
        if(curr_Ind>=piles.size())
            return 0;
        if(dp[curr_Ind][Max_Piles]!=-1)
            return dp[curr_Ind][Max_Piles];
        int total=0;
        int ans=INT_MIN;
        for(int j=0;j<2*Max_Piles;j++){
            if(curr_Ind+j<piles.size())
                total+=piles[curr_Ind+j];
            ans=max(ans,total- recur(curr_Ind+j+1,max(Max_Piles,j+1),piles));
        }
        return dp[curr_Ind][Max_Piles]=ans;
    }
    
    
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(int i=0;i<piles.size();i++)
            sum+=piles[i];
        int diff= recur(0,1,piles);
        return (sum+diff)/2;
    }
};
