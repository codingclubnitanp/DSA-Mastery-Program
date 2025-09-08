#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasZero(int x) {
        while (x > 0) {
            if (x % 10 == 0) return true;
            x /= 10;
        }
        return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int a = i;
            int b = n - a;
            if (!hasZero(a) && !hasZero(b)) {
                return {a, b};
            }
        }
        return {0, 0}; 
    }
};

int main() {
    Solution sol;
    int n = 1317;
    vector<int> ans = sol.getNoZeroIntegers(n);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
