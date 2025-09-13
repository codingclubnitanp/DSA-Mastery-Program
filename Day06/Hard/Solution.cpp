#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        int vowel = 0, conso = 0;
        map<char,int> mpp;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            mpp[c]++;
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                vowel = max(vowel, mpp[c]);
            else
                conso = max(conso, mpp[c]);
        }
        return vowel + conso;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << sol.maxFreqSum(s) << endl;
    return 0;
}
