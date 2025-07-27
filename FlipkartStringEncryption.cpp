#include <bits/stdc++.h>
using namespace std;
int countOnes(int c){
    int count = 0;
    while (c > 0){
        count += c & 1;
        c = c >> 1;
    }
    return count;
}
void encryption(string s, int p){
    unordered_map<char, int> hashmap;
    int start = 0, count = 0, shift = 0;
    for (int i = 0; i < s.size(); ++i){
	//cout << "In the " << i << "th iteration " << s << " Count = " << count << endl;
	if (i == s.size() - 1){
		count += countOnes(s[i]);
		shift = (count - p) % (i - start + 1);
		reverse(s.begin() + start, s.begin() + start + shift);
		reverse(s.begin() + start + shift, s.end());
		reverse(s.begin() + start, s.end());
		//cout << s << " " << i << endl;
	}
        else if (s[i] == ' '){
		shift = (count - p) % (i - start);
		reverse(s.begin() + start, s.begin() + start + shift); // could be s.begin() + i - 1
		//cout << s << endl;
		reverse(s.begin() + start + shift, s.begin() + i);
		//cout << s << endl;
		reverse(s.begin() + start, s.begin() + i);
		//cout << s << " " << i << endl;
		start = i+1;
	    count = 0;
	}
	else if (s[i] >= 'a' && s[i] <= 'z'){
		count += countOnes(s[i]);
	}
    }
	cout << s << endl;
}
int main(){
    string s;
    int p;
	//cout << isalpha('a') << endl;
    getline(cin , s);
	cin >> p;
    for (auto& c : s){
        c = tolower(c);
        //cout << c << " " << countOnes(c) << endl;
    }
	encryption(s, p);
    return 0;
}
