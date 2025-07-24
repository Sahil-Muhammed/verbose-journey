// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/
// Attempt 1: Using a greedy approach
// Outcome: Accepted
class Solution {
public:
    void swap(char& a, char& b){
        char temp = a;
        a = b;
        b = temp;
    }
    int minMovesToMakePalindrome(string s) {
        int left = 0, right = s.size() - 1, count = 0, pos = 0;
        // unordered_map<char, int> freq;
        // for (int i = 0; i < s.size(); ++i){
        //     freq[s[i]]++;
        // }
        // for (int i = 0; i < s.size(); ++i){
        //     cout << freq[s[i]];
        // }
        // cout << endl;
        bool found = false;
        while (left <= right){
            //cout << "Value of count is " << count << endl;
            if (s[left] == s[right]){
                //cout << "works here" << endl;
                left++;
                right--;
                continue;
            }
            found = false;
            for (int i = right - 1; i > left; --i){
                if (s[i] == s[left]){
                    //cout << "\tFound a match at index " << i << endl;
                    found = true;
                    pos = i;
                    break;
                }
                //cout << "Searching for an element that matches with " << s[left] << " but current match is " << s[i] << endl;
            }
            if (found == false){
                //cout << "found is false" << endl;
                pos = left;
                char temp = s[left];
                //while (s[s.size() / 2] != temp && pos < s.size() / 2){
                    //cout << "\tInside while loop " << s[pos] << endl;
                    count++;
                    swap(s[pos], s[pos+1]);
                    pos++;
                //}
                //left++;
                //right--;
                continue;
            }
            while (s[right] != s[left] && found == true && pos < right){
                //cout << "\tI'm here, even length string, so always a match found!" << endl;
                count++;
                swap(s[pos], s[pos+1]);
                pos++;
            }
            left++;
            right--;
        }
        //cout << "Length of string is " << s.size() << endl;
        //cout << s << endl;
        // for (int i = 0; i < s.size(); ++i){
        //     cout << freq[s[i]];
        // }
        // cout << endl;
        return count;
    }
};
