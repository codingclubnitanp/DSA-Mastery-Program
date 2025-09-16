import java.util.*;

class Solution {
    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        
        for (int num : nums) {
            long curr = num;
            while (!ans.isEmpty() && gcd(curr, ans.get(ans.size() - 1)) > 1) {
                curr = lcm(curr, ans.get(ans.size() - 1));
                ans.remove(ans.size() - 1);
            }
            ans.add((int) curr); 
        }
        return ans;
    }
    
    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    private long lcm(long a, long b) {
        return a / gcd(a, b) * b;
    }
}

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[] nums = {6, 4, 3};
        List<Integer> result = sol.replaceNonCoprimes(nums);

        System.out.print("Result: ");
        for (int x : result) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
}
