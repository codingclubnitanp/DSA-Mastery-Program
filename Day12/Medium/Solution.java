class Solution {
    public int maxProfit(int[] prices) {
       int max = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < prices.length; i++) {
            min = Math.min(min, prices[i]);
            int pr = prices[i] - min;
            max = Math.max(pr, max);
        }
        return max;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] prices = {7, 1, 5, 3, 6, 4};
        System.out.println(sol.maxProfit(prices)); // Expected: 5
    }
}
