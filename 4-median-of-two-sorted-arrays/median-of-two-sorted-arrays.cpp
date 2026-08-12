class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size() + nums2.size());
        merge(nums1.begin(), nums1.end(),nums2.begin(), nums2.end(),result.begin());
        int i = result.size();
        if (i % 2 == 1) {
            return result[i/2];
        }
        else {
            return (result[i/2-1] + result[i/2])/2.0;
        }
    }
};