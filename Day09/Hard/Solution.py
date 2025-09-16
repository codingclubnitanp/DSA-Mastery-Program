class Solution(object):
    def replaceNonCoprimes(self, nums):
        ans = []
        
        for num in nums:
            curr = num
            while ans and gcd(curr, ans[-1]) > 1:
                curr = self.lcm(curr, ans[-1])
                ans.pop()
            ans.append(curr)
        
        return ans
    
    def lcm(self, a, b):
        return a // gcd(a, b) * b

if __name__ == "__main__":
    sol = Solution()
    nums = [6, 4, 3]
    result = sol.replaceNonCoprimes(nums)
    print("Result:", result)
