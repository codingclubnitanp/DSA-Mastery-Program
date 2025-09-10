import java.util.*;

class Solution {
    private boolean common(int[][] languages, int u, int v) {
        for (int a : languages[u]) {
            for (int b : languages[v]) {
                if (a == b) return true;
            }
        }
        return false;
    }

    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        Set<Integer> need = new HashSet<>();
        for (int[] f : friendships) {
            int u = f[0], v = f[1];
            if (!common(languages, u - 1, v - 1)) {
                need.add(u);
                need.add(v);
            }
        }

        if (need.isEmpty()) return 0;
        Map<Integer, Integer> mpp = new HashMap<>();
        int maxi = 0;
        for (int person : need) {
            for (int lang : languages[person - 1]) {
                mpp.put(lang, mpp.getOrDefault(lang, 0) + 1);
                maxi = Math.max(maxi, mpp.get(lang));
            }
        }

        return need.size() - maxi;
    }
}


public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int n = 3;
        int[][] languages = {{2}, {1, 3}, {1, 2}};
        int[][] friendships = {{1, 2}, {1, 3}, {2, 3}};

        System.out.println("Minimum Teachings: " +
                           sol.minimumTeachings(n, languages, friendships));
    }
}
