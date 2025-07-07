class Solution {
public:
    int calcBouquet(vector<int> bloomDay, int m, int k, int day){
        int ans = 0;
        for (int i = 0; i < bloomDay.size(); ++i){
            bloomDay[i] -= day;
        }
        int left = 0, right = 0;
        for (right = 0; right < bloomDay.size(); ++right){
            if (bloomDay[right] <= 0){
                if (right - left + 1 >= k){
                    ans++;
                    left = right + 1;
                }
            }
            else{
                left = right + 1;
            }
        }
        if (right - left >= k){
            ans++;
        }
        return ans;
    }
    int binSearch(vector<int> bloomDay, int m, int k, int max, int min){
        int low = min, high = max, ans = 11;
        while (low <= high){
            int mid = (low+high)/2;
            int val = calcBouquet(bloomDay, m, k, mid);
            cout << val << endl;
            if (val >= m){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()){
            return -1;
        }
        int max = INT_MIN, min = INT_MAX;
        for(int i = 0; i < bloomDay.size(); ++i){
            if (bloomDay[i] > max){
                max = bloomDay[i];
            }
            if (bloomDay[i] < min){
                min = bloomDay[i];
            }
        }
        return binSearch(bloomDay, m, k, max, min);
    }
};
