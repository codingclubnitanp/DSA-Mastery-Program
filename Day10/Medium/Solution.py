class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        candidate = None
        
        for num in nums:
            if count == 0:
                candidate = num
            
            if num == candidate:
                count += 1
            else:
                count -= 1
                
        return candidate

if __name__ == "__main__":
    nums = [2, 2, 1, 1, 1, 2, 2]
    sol = Solution()
    result = sol.majorityElement(nums)
    print("Majority Element:", result)
