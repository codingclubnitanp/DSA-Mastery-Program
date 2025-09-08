class Solution {
    public int countDigits(int n) {
        int c = 0;
        while (n > 0) {
            c++;
            n = n / 10;
        }
        return c;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.countDigits(12345)); // Example usage
    }
}
