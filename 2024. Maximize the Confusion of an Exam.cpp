class Solution {
public:
    int solve(string a, int k,char c){
        int i=0;
        int j=0;
        int count=0;
        int n=a.size();
        int ans=0;
          while(j<n){
          if(a[j]==c)
          count++;
          while(i<n&&count>k){
           if(a[i]==c)
           count--;
           i++;
          }  
          ans=max(j-i+1,ans);
          j++;
        }
        return ans;
    }
    int maxConsecutiveAnswers(string a, int k) {
       
        int ans1=solve(a,k,'T');
        int ans2=solve(a,k,'F');
         return max(ans1,ans2);
    }
};
