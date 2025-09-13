import java.util.*;

class Solution {
    public boolean armstrongNumber(int n) {
        int sum = 0, x = n;
        while (x > 0) {
            int d = x % 10;
            sum += Math.pow(d, 3);
            x /= 10;
        }
        return sum == n;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Solution sol = new Solution();
        System.out.println(sol.armstrongNumber(n));
        sc.close();
    }
}
