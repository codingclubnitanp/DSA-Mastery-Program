class Solution:
    def print2largest(self, arr):
        largest = -1
        second_largest = -1
        
        for num in arr:
            if num > largest:
                second_largest = largest
                largest = num
            elif num > second_largest and num != largest:
                second_largest = num
                
        return second_largest

if __name__ == "__main__":
    arr = [12, 35, 1, 10, 34, 1]
    sol = Solution()
    result = sol.print2largest(arr)
    print("Second largest element:", result)
    
