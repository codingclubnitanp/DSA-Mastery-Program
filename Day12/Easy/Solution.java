class Solution {
    int print2largest(int arr[], int n) {
        int largest = -1;
        int secondLargest = -1;

        for (int i = 0; i < n; i++) {
            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            } else if (arr[i] > secondLargest && arr[i] != largest) {
                secondLargest = arr[i];
            }
        }
        return secondLargest;
    }
}

public class Main {
    public static void main(String[] args) {
        int[] arr = {12, 35, 1, 10, 34, 1};
        Solution sol = new Solution();
        int result = sol.print2largest(arr, arr.length);
        System.out.println("Second largest element: " + result);
    }
}
