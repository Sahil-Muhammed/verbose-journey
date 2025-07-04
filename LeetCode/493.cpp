// https://leetcode.com/problems/reverse-pairs/submissions/1684377883/
// Attempt 1: Brute force
// Outcome: 33/140; TLE
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
    for (int i = 0; i < nums.size(); ++i){
        long long num1 = nums[i];
        for (int j = i + 1; j < nums.size(); ++j){
            long long num2 = nums[j];
            if (num1 > 2*num2){
                count++;
            }
        }
    }
    return count;
    }
};
// Attempt 2: Using merge sort, with count function before merging
// Outcome: Accepted
class Solution {
public:
    void merge(std::vector<int>& nums, int low, int mid, int high){
    int i = low, j = mid+1;
    std::vector<int> arr;
    while (i <= mid && j <= high){
        if (nums[i] > nums[j]){
            arr.push_back(nums[j++]);
        }
        else{
            arr.push_back(nums[i++]);
        }
    }
    while (i <= mid){
        arr.push_back(nums[i++]);
    }
    while (j <= high){
        arr.push_back(nums[j++]);
    }
    for (int i = low; i <= high; ++i){
        nums[i] = arr[i-low];
    }
}
int countReverse(vector<int> nums, int low, int mid, int high){
    int count = 0, j = mid+1;
    for (int i = low; i <= mid; ++i){
        while (j <= high && nums[i] > 2 * (long) nums[j]){
            j++;
        }
        count += (j-(mid+1));
    }
    return count;
}
int divide(std::vector<int>& nums, int low, int high){
    int count1 = 0;
    if (low >= high){
        return 0;
    }
    int mid = (low+high)/2, j = mid+1;
    count1 += divide(nums, low, mid);
    count1 += divide(nums, mid+1, high);
    for (int i = low; i <= mid; ++i){
        while (j <= high && nums[i] > 2*(long)nums[j]){
            j++;
        }
        count1 += (j-mid-1);
    }
    merge(nums, low, mid, high);
    return count1;
}
    int reversePairs(vector<int>& nums) {
        return divide(nums, 0, nums.size() - 1);
    }
};
