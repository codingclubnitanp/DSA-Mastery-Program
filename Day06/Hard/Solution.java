import java.util.*;

class Solution {
    public int maxFreqSum(String s) {
        int vowel = 0, conso = 0;
        HashMap<Character, Integer> map = new HashMap<>();
        
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') {
                vowel = Math.max(vowel, map.get(c));
            } else {
                conso = Math.max(conso, map.get(c));
            }
        }
        return vowel + conso;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Solution sol = new Solution();
        System.out.println(sol.maxFreqSum(s));
        sc.close();
    }
}
