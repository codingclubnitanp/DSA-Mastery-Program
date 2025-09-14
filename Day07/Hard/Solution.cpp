#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;

        for (string word : wordlist) {
            string lower = toLower(word);
            string devowelStr = devowel(lower);

            if (!caseInsensitive.count(lower))
                caseInsensitive[lower] = word;

            if (!vowelInsensitive.count(devowelStr))
                vowelInsensitive[devowelStr] = word;
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lowerQ = toLower(q);
            if (caseInsensitive.count(lowerQ)) {
                ans.push_back(caseInsensitive[lowerQ]);
                continue;
            }

            string devowelQ = devowel(lowerQ);
            if (vowelInsensitive.count(devowelQ)) {
                ans.push_back(vowelInsensitive[devowelQ]);
                continue;
            }

            ans.push_back("");
        }

        return ans;
    }

private:
    string toLower(const string& s) {
        string res = s;
        for (char& c : res) c = tolower(c);
        return res;
    }

    string devowel(const string& s) {
        string res = s;
        for (char& c : res) {
            if (isVowel(c)) c = '*';
        }
        return res;
    }

    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

int main() {
    Solution sol;

    vector<string> wordlist = {"KiTe","kite","hare","Hare"};
    vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};

    vector<string> ans = sol.spellchecker(wordlist, queries);

    for (string s : ans) cout << "\"" << s << "\" ";
    cout << endl;

    return 0;
}
