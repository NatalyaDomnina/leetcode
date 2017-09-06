'''
Given a non negative integer number num. For every numbers i in 
the range 0 ≤ i ≤ num calculate the number of 1's in their binary 
representation and return them as an array.
Example:
For num = 5 you should return [0,1,1,2,1,2].
'''
class Solution(object):
    def countBits(self, num):
        l = []
        for i in range(num+1):
            l.append(self.sumF(i))
        return l

    def sumF (self, num):
        sum_el = 0
        while num > 0:
            sum_el += num % 2
            num = num // 2
        return sum_el

a = 5
s = Solution()
print (s.countBits(a))