class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int low = 0, high = nums1.size(), mid2 = -1;
        if (nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }
        int halfsize = (nums1.size() + nums2.size() + 1) / 2;
        while (low <= high){
            int mid1 = (low+high)/2;
            int mid2 = halfsize - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if (mid1 >= 1){
                l1 = nums1[mid1-1];
            }
            if (mid2 >= 1){
                l2 = nums2[mid2-1];
            }
            if (mid1 < nums1.size()){
                r1 = nums1[mid1];
            }
            if (mid2 < nums2.size()){
                r2 = nums2[mid2];
            }
            if (l1 <= r2 && l2 < r1){
                if ((nums1.size() + nums2.size()) % 2 == 1){
                    return max(l1, l2);
                }
                else{
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
            else if (l1 <= r2){
                low = mid1 + 1;
            }
            else{
                high = mid1 - 1;
            }
        }
        return 0;
    }
};