#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int n = x;
        long long rev = 0;
        while (n != 0) {
            rev = rev * 10 + (n % 10);
            n = n / 10;
        }
        return (rev == x);
    }
};

int main() {
    Solution sol;
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (sol.isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }
    return 0;
}
