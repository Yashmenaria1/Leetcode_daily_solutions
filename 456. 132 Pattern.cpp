class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        int n=arr.size();
        int k=INT_MIN;
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]<k)return true;
            else {
                while(!st.empty() and arr[i]>st.top()){
                    k=st.top();
                    st.pop();
                }
            }
            st.push(arr[i]);
        }
        return false;
    }
};
