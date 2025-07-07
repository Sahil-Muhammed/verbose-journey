// https://leetcode.com/problems/koko-eating-bananas/description/
// Attempt 1: Using binary search over search space
class Solution {
public:

    int timeTaken(vector<int> piles, int speed, int h){
        int count = 0;
        for (int i = 0; i < piles.size(); ++i){
            count += ceil((double)piles[i] / speed);
            if (count > h){
                return h+1;
            }
        }
        return count;
    }
    int binSearch(vector<int> piles, int target, int h){
        int low = 1, high = target;
        while (low <= high){
            int mid = (low+high)/2;
            if (timeTaken(piles, mid, h) > h){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = INT_MIN;
        for (int i = 0; i < piles.size(); ++i){
            if (max < piles[i]){
                max = piles[i];
            }
        }
        return binSearch(piles, max, h);
    }
};
