class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        boolean broken = false;
        int ans = 0;

        for (int i = 0; i < text.length(); i++) {
            if (text.charAt(i) == ' ') {
                if (!broken) ans++;
                broken = false;
            }
            for (int j = 0; j < brokenLetters.length(); j++) {
                if (text.charAt(i) == brokenLetters.charAt(j)) {
                    broken = true;
                }
            }
        }

        if (!broken) ans++;
        return ans;        
    }
}

public class Main {
    public static void main(String[] args) {
        String text = "hello world";
        String brokenLetters = "ad";

        Solution sol = new Solution();
        int result = sol.canBeTypedWords(text, brokenLetters);

        System.out.println("Number of words that can be typed: " + result);
    }
}
