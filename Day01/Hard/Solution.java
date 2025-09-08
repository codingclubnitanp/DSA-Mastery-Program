class Solution {
    private boolean hasZero(int x) {
        while (x > 0) {
            if (x % 10 == 0) return true;
            x /= 10;
        }
        return false;
    }

    public int[] getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int a = i, b = n - i;
            if (!hasZero(a) && !hasZero(b)) {
                return new int[]{a, b};
            }
        }
        return new int[]{0, 0};
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] ans = sol.getNoZeroIntegers(1317);
        System.out.println(ans[0] + " " + ans[1]);
    }
}
