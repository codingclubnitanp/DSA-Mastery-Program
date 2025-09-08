#include <iostream>
using namespace std;

class Solution {
  public:
    int countDigits(int n) {
        int c = 0;
        while (n > 0) {
            c++;
            n = n / 10;
        }
        return c;
    }
};

int main() {
    Solution sol;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Number of digits: " << sol.countDigits(n) << endl;
    return 0;
}
