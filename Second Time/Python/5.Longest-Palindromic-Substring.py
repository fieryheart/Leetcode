class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ""
        for i in range(len(s)):
            tmp = self.findPalindrome(s, i, i)
            if len(tmp) > len(res):
                res = tmp
            tmp = self.findPalindrome(s, i, i+1)
            if len(tmp) > len(res):
                res = tmp
        return res
    def findPalindrome(self, s, left, right) -> str:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left+1:right]