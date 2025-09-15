class Solution:
    def twoSum(self, nums, target):
        arr = [(val, idx) for idx, val in enumerate(nums)]
        arr.sort()
        i, j = 0, len(arr)-1
        while i < j:
            s = arr[i][0] + arr[j][0]
            if s == target:
                return [arr[i][1], arr[j][1]]
            elif s < target:
                i += 1
            else:
                j -= 1
        return [-1, -1]

if __name__ == "__main__":
    sol = Solution()
    nums = [2,7,11,15]
    target = 9
    ans = sol.twoSum(nums, target)
    print(ans[0], ans[1])
