class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int minus = -1, tempSum = 0;
        unordered_map<char, int> val = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        if (s.size() == 1){
            return val[s[0]];
        }
        int j = 0;
        while (j < s.size() - 1){
            if (val[s[j]] < val[s[j+1]]){
                sum -= val[s[j]]; 
            }
            else{
                sum += val[s[j]];
            }
            j++;
        }
        sum += val[s[j]];
        return sum;
    }
};