'''
The Hamming distance between two integers is the number of 
positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
'''
class Solution(object):
    def hammingDistance(self, x, y):
        a = "0"
        b = "0"
        i = 0
        res = 0
        while x > 0 or y > 0:
            if x > 0 and y == 0:
                b += '0'
            if y > 0 and x == 0:
                a += '0'
            if x > 0:        
                a += str(x % 2)
                x = int(x / 2)
            if y > 0:
                b += str(y % 2)
                y = int(y / 2)            
            if a[i] != b[i]:        
                res += 1    
            i += 1        
        if a[i] != b[i]: 
            res += 1        
        return res

obj = Solution()
obj.hammingDistance(1,4)