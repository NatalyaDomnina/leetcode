'''
Given a positive integer, output its complement number. The complement
strategy is to flip the bits of its binary representation.
Note:
1. The given integer is guaranteed to fit within the range of a 32-bit signed integer.
2. You could assume no leading zero bit in the integer’s binary representation.
'''

class Solution(object):
    def findComplement(self, num):
        res = ""
        snum = bin(num)
        snum = snum[snum.index('b')+1:]
        for i in snum:
            res += str(int(i) ^ int(1))
        return int(res,2)

s = Solution()
print (s.findComplement(5))