class Solution {
public:
    bool check(int mid,vector<int>& cookies,int k){
        int n=cookies.size();
        int child=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=cookies[i];
            if(mid<cookies[i]) return false;
            if(sum>mid){
                child++;
                sum=cookies[i];
            }
            if(child>k) return false;
        }
        return true;
    }
    int binarySearch(vector<int>& cookies,int k,int sum){
        int start=0;
        int end=sum;
        int ans=0;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(check(mid,cookies,k)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies,int k){
        sort(cookies.begin(),cookies.end());
        int sum=accumulate(cookies.begin(),cookies.end(),0);
        int ans=1e8;
        do{
            ans=min(ans,binarySearch(cookies,k,sum));   
        }
        while(next_permutation(cookies.begin(),cookies.end()));  
        return ans;
    }
};
