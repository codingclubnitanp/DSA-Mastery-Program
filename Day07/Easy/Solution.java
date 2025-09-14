import java.util.Scanner;

class Solution {
    public int largestPrimeFactor(int n) {
        long maxi = -1;
        while (n % 2 == 0) {
            n /= 2;
            maxi = 2;
        }
        for (long i = 3; i * i <= n; i += 2) {
            while (n % i == 0) {
                n /= i;
                maxi = i;
            }
        }
        if (n > 2) {
            maxi = n;
        }
        return (int)maxi;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Solution sol = new Solution();
        System.out.println(sol.largestPrimeFactor(n));
        sc.close();
    }
}
