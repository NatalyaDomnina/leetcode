'''
Given two strings representing two complex numbers.
You need to return a string representing their multiplication.
'''
class Solution(object):
    def complexNumberMultiply(self, a, b):
        spA = a.index('+')
        spB = b.index('+')
        a1, a2 = int(a[:spA]), int(a[spA+1:-1])
        b1, b2 = int(b[:spB]), int(b[spB+1:-1])
        pr = str(a1*b1 + a2*b2*(-1)) + '+' + str(a1*b2 + a2*b1) + 'i'
        return pr

l1 = "1+-1i"
l2 = "1+-1i"
s = Solution()
print(s.complexNumberMultiply(l1, l2))