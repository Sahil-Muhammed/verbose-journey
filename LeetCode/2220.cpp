// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/
// Attempt 1: Using XOR and then finding the number of set bits in it
// Outcome: Accepted
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int excOR = start ^ goal;
        int count = 0;
        while (excOR > 0){
            count++;
            excOR = excOR & (excOR-1);
        }
        return count;
    }
};
