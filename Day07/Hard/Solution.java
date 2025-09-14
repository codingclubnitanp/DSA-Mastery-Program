import java.util.*;

class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> exact = new HashSet<>(Arrays.asList(wordlist));
        Map<String, String> caseInsensitive = new HashMap<>();
        Map<String, String> vowelInsensitive = new HashMap<>();

        for (String word : wordlist) {
            String lower = word.toLowerCase();
            String devowel = devowel(lower);
            caseInsensitive.putIfAbsent(lower, word);
            vowelInsensitive.putIfAbsent(devowel, word);
        }

        String[] ans = new String[queries.length];
        for (int k = 0; k < queries.length; k++) {
            String q = queries[k];
            if (exact.contains(q)) {
                ans[k] = q;
                continue;
            }

            String lowerQ = q.toLowerCase();
            if (caseInsensitive.containsKey(lowerQ)) {
                ans[k] = caseInsensitive.get(lowerQ);
                continue;
            }

            String devowelQ = devowel(lowerQ);
            if (vowelInsensitive.containsKey(devowelQ)) {
                ans[k] = vowelInsensitive.get(devowelQ);
                continue;
            }

            ans[k] = "";
        }
        return ans;
    }

    private String devowel(String s) {
        return s.replaceAll("[aeiou]", "*");
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] wordlist = {"KiTe","kite","hare","Hare"};
        String[] queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
        String[] ans = sol.spellchecker(wordlist, queries);

        for (String s : ans) System.out.print("\"" + s + "\" ");
        System.out.println();
    }
}
