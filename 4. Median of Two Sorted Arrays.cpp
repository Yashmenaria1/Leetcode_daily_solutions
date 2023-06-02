class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> d; 
        d.resize(nums1.size()+nums2.size());
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),d.begin());
        if(d.size()%2) return (double)d[d.size()/2];
        return (((double)d[d.size()/2])+((double)d[d.size()/2-1]))/2.0;
    }
};
