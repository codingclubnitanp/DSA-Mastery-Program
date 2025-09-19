#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int minVal = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            minVal = min(minVal, prices[i]);
            int pr = prices[i] - minVal;
            max = std::max(pr, max);
        }
        return max;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl; // Expected: 5
    return 0;
}
