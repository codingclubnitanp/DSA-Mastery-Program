#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
                return true;
            }
        }
        return false;
    }
};

int main() {
    string s;
    cin >> s;
    Solution sol;
    cout << (sol.doesAliceWin(s) ? "true" : "false") << endl;
    return 0;
}
