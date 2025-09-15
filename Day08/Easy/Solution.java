import java.util.*;

class Solution {
    public void reverseArray(int[] arr) {
        int i = 0, j = arr.length - 1;
        while(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = {1, 2, 3, 4, 5};
        sol.reverseArray(arr);

        System.out.print("Reversed array: ");
        for(int x : arr){
            System.out.print(x + " ");
        }
        System.out.println();
    }
}
