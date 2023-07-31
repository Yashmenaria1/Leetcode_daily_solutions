class Solution {
public:
	int minimumDeleteSum(string s1, string s2) {
		int n=s1.size();
		int m=s2.size();
		int sum1=0,sum2=0;
		for(auto i:s1) sum1+=i;
		for(auto i:s2) sum2+=i;
		vector<int> prev(m+1,0),curr(m+1,0);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s1[i-1]==s2[j-1]) curr[j]=s1[i-1]+prev[j-1];
				else curr[j]=max(prev[j],curr[j-1]);
			}   
			prev=curr;
		}
		return (sum1+sum2)-2*prev[m];
	}
};
