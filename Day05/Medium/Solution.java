import java.util.*;

class Solution {
    public void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int p = partition(arr, low, high);
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }

    public int partition(int[] arr, int low, int high) {
        int i = low, j = high;
        int pivot = arr[low];
        while (i < j) {
            while (arr[i] <= pivot && i < high) i++;
            while (arr[j] > pivot && j > low) j--;
            if (i < j) {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
        int tmp = arr[low];
        arr[low] = arr[j];
        arr[j] = tmp;
        return j;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        Solution sol = new Solution();
        sol.quickSort(arr, 0, n - 1);

        for (int x : arr) System.out.print(x + " ");
        System.out.println();
        sc.close();
    }
}
