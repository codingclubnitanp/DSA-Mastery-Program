import java.util.Scanner;

class Solution {
    public void merge(int[] arr, int l, int mid, int r) {
        int[] res = new int[r - l + 1];
        int i = l, j = mid + 1, c = 0;

        while (i <= mid && j <= r) {
            if (arr[i] <= arr[j]) res[c++] = arr[i++];
            else res[c++] = arr[j++];
        }
        while (i <= mid) res[c++] = arr[i++];
        while (j <= r) res[c++] = arr[j++];

        for (int k = 0; k < c; k++) arr[l + k] = res[k];
    }

    public void mergeSort(int[] arr, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            mergeSort(arr, l, mid);
            mergeSort(arr, mid + 1, r);
            merge(arr, l, mid, r);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Solution sol = new Solution();

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();
        int[] arr = new int[n];
        System.out.print("Enter elements: ");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        sol.mergeSort(arr, 0, n - 1);

        System.out.print("Sorted array: ");
        for (int x : arr) System.out.print(x + " ");
        System.out.println();

        sc.close();
    }
}
