import java.util.*;

class Solution {
    public boolean doesAliceWin(String s) {
        for (char c : s.toCharArray()) {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
                return true;
            }
        }
        return false;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Solution sol = new Solution();
        System.out.println(sol.doesAliceWin(s));
        sc.close();
    }
}
