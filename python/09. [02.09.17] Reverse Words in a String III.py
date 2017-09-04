'''
Given a string, you need to reverse the order of characters in each word
within a sentence while still preserving whitespace and initial word order.
Example:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
'''
class Solution(object):
    def reverseWords(self, s):
        sSpl = s.split(' ')
        res = ""
        for word in sSpl:
            res += word[::-1] + ' '
        return res[:-1]

l = "Let's take LeetCode contest"
s = Solution()
print (s.reverseWords(l))