import java.util.Scanner;

class Solution {
    public int reverse(int x) {
        long sum = 0;
        while (x != 0) {
            sum = sum * 10 + (x % 10);
            x = x / 10;
            if (sum > Integer.MAX_VALUE || sum < Integer.MIN_VALUE) {
                return 0;
            }
        }
        return (int)sum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Solution sol = new Solution();

        System.out.print("Enter an integer: ");
        int n = sc.nextInt();

        int result = sol.reverse(n);
        System.out.println("Reversed integer: " + result);

        sc.close();
    }
}
