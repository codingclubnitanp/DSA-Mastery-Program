class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        final int MOD = 1000000007;
        long[] dp = new long[n + 1];
        dp[1] = 1;

        long share = 0;
        for (int day = 2; day <= n; day++) {
            if (day - delay >= 1) {
                share = (share + dp[day - delay]) % MOD;
            }
            if (day - forget >= 1) {
                share = (share - dp[day - forget] + MOD) % MOD;
            }
            dp[day] = share;
        }

        long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % MOD;
        }
        return (int) ans;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.peopleAwareOfSecret(6, 2, 4)); 
    }
}
