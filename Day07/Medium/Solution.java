import java.util.*;

class Solution {
    public void mergeArrays(int[] a, int[] b) {
        int n = a.length, m = b.length;
        int i = n - 1, j = 0;

        while (i >= 0 && j < m) {
            if (a[i] > b[j]) {
                int temp = a[i];
                a[i] = b[j];
                b[j] = temp;
                i--;
                j++;
            } else {
                j++;
            }
        }

        Arrays.sort(a);
        Arrays.sort(b);
    }

    public static void main(String[] args) {
        int[] a = {1, 5, 9, 10, 15, 20};
        int[] b = {2, 3, 8, 13};

        Solution s = new Solution();
        s.mergeArrays(a, b);

        System.out.print("Array A: ");
        for (int x : a) System.out.print(x + " ");
        System.out.println("\nArray B: ");
        for (int x : b) System.out.print(x + " ");
    }
}
