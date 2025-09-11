#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vs;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                vs.push_back(s[i]);
                s[i] = '^';
            }
        }
        sort(vs.begin(), vs.end());
        int c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '^') {
                s[i] = vs[c++];
            }
        }
        return s;
    }

    bool isVowel(char ch) {
        return ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U';
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    cout << "String after sorting vowels: " << sol.sortVowels(s) << endl;
    return 0;
}
