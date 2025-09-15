#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken = false;
        int ans = 0;
        for (int i = 0; i < text.length(); i++) {
            if (text[i] == ' ') {
                ans += !broken;
                broken = false;
            }           
            for (int j = 0; j < brokenLetters.length(); j++) {
                if (text[i] == brokenLetters[j]) {
                    broken = true;
                }
            }
        }
        ans += !broken;
        return ans;
    }
};

int main() {
    string text, brokenLetters;

    text = "hello world";
    brokenLetters = "ad";

    Solution sol;
    int result = sol.canBeTypedWords(text, brokenLetters);

    cout << "Number of words that can be typed: " << result << endl;

    return 0;
}
