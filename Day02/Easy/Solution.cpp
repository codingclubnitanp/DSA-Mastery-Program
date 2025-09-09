#include <iostream>
#include <climits>   
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long sum = 0;
        while (x != 0) {
            sum = sum * 10 + (x % 10);
            x = x / 10;
            if (sum > INT_MAX || sum < INT_MIN) {
                return 0;
            }
        }
        return (int)sum;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter an integer: ";
    cin >> n;

    int result = sol.reverse(n);
    cout << "Reversed integer: " << result << endl;

    return 0;
}
