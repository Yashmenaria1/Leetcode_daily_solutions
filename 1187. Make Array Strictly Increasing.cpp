class Solution {
public:
    int binarysearch( vector<int>&arr , int prev , int index ){
        int n = arr.size() ;
        int low = index ; 
        int high = n-1; 
        while (low<=high){
            int mid = low+(high - low)/2 ; 
            if ( arr[mid]> prev){
                n = mid ; 
                high = mid -1 ; 
            } 
            else
                low = mid +1 ; 
        }
        return n ; 
    }
    int dp[2001][2001]; 
    int solve ( vector<int>&arr1, vector<int>&arr2, int i, int j, int prev  ){
        if ( i ==arr1.size()) return 0 ; 
        j = binarysearch(arr2, prev , j ); 
        if ( dp[i][j]!=-1) return dp[i][j]; 
        if ( arr1[i]<=prev && j ==arr2.size()) return 2001; 
        int take = 2001, nottake= 2001; 
        if ( j!=arr2.size())
        take = 1+solve ( arr1, arr2, i+1 , j+1,arr2[j]);
        if(arr1[i] > prev)
        nottake = solve (arr1, arr2 , i+1 ,j , arr1[i]); 
        return  dp[i][j] = min ( take , nottake) ; 
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        memset(dp , -1, sizeof(dp));
        sort(arr2.begin() , arr2.end()); 
        int res = solve( arr1, arr2, 0, 0, -1 ); 
        if ( res >arr1.size() ) return -1 ; 
        return res; 
    }
};
