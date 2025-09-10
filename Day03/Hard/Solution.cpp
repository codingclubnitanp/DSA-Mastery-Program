#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool common(vector<vector<int>>& languages, int u, int v) {
        for (int a : languages[u]) {
            for (int b : languages[v]) {
                if (a == b) return true;
            }
        }
        return false;
    }

    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        set<int> st;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            if (!common(languages, u - 1, v - 1)) {
                st.insert(u);
                st.insert(v);
            }
        }
        if (st.empty()) return 0;

        int maxi = INT_MIN;
        map<int,int> mpp;
        for (int person : st) {
            int s = person - 1;
            for (int lang : languages[s]) {
                mpp[lang]++;
                maxi = max(maxi, mpp[lang]);
            }
        }
        return st.size() - maxi;
    }
};

int main() {
    Solution sol;

    int n = 3;
    vector<vector<int>> languages = {{2}, {1, 3}, {1, 2}};
    vector<vector<int>> friendships = {{1, 2}, {1, 3}, {2, 3}};

    cout << "Minimum Teachings: " << sol.minimumTeachings(n, languages, friendships) << endl;
    return 0;
}
