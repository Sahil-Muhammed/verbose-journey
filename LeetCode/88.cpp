// https://leetcode.com/problems/merge-sorted-array/
// Attempt 1: Use merge sort "merge" logic
// Outcome: Accepted
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(nums1.begin(), nums1.begin() + m);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n){
            if (nums2[j] >= nums3[i]){
                nums1[k++] = nums3[i++];
            }
            else{
                nums1[k++] = nums2[j++];
            }
        }
        while (i < m){
            nums1[k++] = nums3[i++];
        }
        while (j < n){
            nums1[k++] = nums2[j++];
        }
    }
};
