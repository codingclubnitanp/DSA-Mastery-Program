import java.util.*;

class Solution {
    public void selectionSort(int[] arr) {
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int maxi = arr[0];
            int maxiInd = 0;
            for (int j = 0; j < n - i; j++) {
                if (arr[j] > maxi) {
                    maxi = arr[j];
                    maxiInd = j;
                }
            }
            int temp = arr[n - i - 1];
            arr[n - i - 1] = arr[maxiInd];
            arr[maxiInd] = temp;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Solution sol = new Solution();

        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.print("Enter elements: ");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        sol.selectionSort(arr);

        System.out.print("Sorted array: ");
        for (int x : arr) System.out.print(x + " ");
        System.out.println();
        sc.close();
    }
}
