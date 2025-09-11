import java.util.*;

class Solution {
    public String sortVowels(String s) {
        List<Character> vowels = new ArrayList<>();
        List<Integer> pos = new ArrayList<>();
        
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            if (isVowel(ch)) {
                vowels.add(ch);
                pos.add(i);
            }
        }
        
        Collections.sort(vowels);
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i < pos.size(); i++) {
            sb.setCharAt(pos.get(i), vowels.get(i));
        }
        return sb.toString();
    }

    private boolean isVowel(char ch) {
        return "aeiouAEIOU".indexOf(ch) != -1;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Solution sol = new Solution();
        System.out.print("Enter a string: ");
        String s = sc.nextLine();
        System.out.println("String after sorting vowels: " + sol.sortVowels(s));
        sc.close();
    }
}
