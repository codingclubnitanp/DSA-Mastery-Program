class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        Integer candidate = null;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1; //ternary operator(alternative for if-else)
        }

        return candidate;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {2, 2, 1, 1, 1, 2, 2};
        Solution sol = new Solution();
        int result = sol.majorityElement(nums);
        System.out.println("Majority Element: " + result);
    }
}
