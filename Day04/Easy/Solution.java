import java.util.Scanner;

class Solution {
    public int gcd(int a, int b) {
        while (a > 0 && b > 0) {
            if (a >= b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }
        if (a == 0) return b;
        return a;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Solution sol = new Solution();
        System.out.print("Enter two numbers: ");
        int a = sc.nextInt();
        int b = sc.nextInt();
        System.out.println("GCD is: " + sol.gcd(a, b));
        sc.close();
    }
}
