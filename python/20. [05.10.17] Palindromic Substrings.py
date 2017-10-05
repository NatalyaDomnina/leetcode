'''
Given a string, your task is to count how many palindromic
substrings in this string. The substrings with different
start indexes or end indexes are counted as different
substrings even they consist of same characters.
'''
class Solution:
    def reverce(self, s, s1, s2):
        res = 0
        i = s2
        j = s1
        while i < len(s) and j >= 0:
            if s[i] != s[j]:
                break
            else:
                res += 1
                i += 1
                j -= 1
        return res

    def countSubstrings(self, s):
        if len(s) == 1:
            return 1
        res = 0
        for r in range(len(s)):
            res += self.reverce(s, r, r)
            res += self.reverce(s, r, r+1)
        return res

l = "aba"
s = Solution()
print(s.countSubstrings(l))