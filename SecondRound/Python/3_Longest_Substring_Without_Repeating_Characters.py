class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        start = maxl = 0
        dic = {}
        for i in range(len(s)):
            if s[i] in dic and start <= dic[s[i]]:
                start = dic[s[i]]+1
            else:
                maxl = max(maxl, i-start+1)
            dic[s[i]] = i
        return maxl