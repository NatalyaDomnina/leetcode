'''
Validate if a given string is numeric.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
'''
class Solution(object):
    def isNumber(self, s):
        sample = "0123456789"
        l = len(s)
        res1, pm, pme, te = 0, 0, 0, 0
        for i in range(l):
            if s[i] in sample:
                res1 += 1
        s = s.strip(' ')

        l = len(s)
        s = ' ' + s + ' '

        if s.count('.') > 1 or s.count('e') > 1:
            return False
        if res1 == 0:
            return False
        if s[1] == '-' or s[1] == '+':
            pm = 1
        if res1 == l - pm:
            return True
        if s.count('.') == 1:
            if s[s.index('.')-1] not in sample:
                if s[s.index('.')+1] not in sample:
                    return False
        if s.count('e') == 1:
            if s.index('e') < l-1:
                if s[s.index('e')+1] == '+' or s[s.index('e')+1] == '-':
                    pme = 1
        if s.count('e') == 1:
            if s[s.index('e')+1] == ' ':
                return False
        if s.count('e') == 1:
            if s.index('e') > 1:
                if s[s.index('e')-1] == '+' or s[s.index('e')-1] == '-':
                    return False
        if s.count('.') == 1:
            if s.count('e') == 1:
                if s.index('.') < s.index('e'):
                    te = 1
        if s.count('.') == 1:
            if res1 == l - 1 - pm:
                return True
        if s.count('e') == 1:
            if s.index('e')-1 <= l - 1:
                if s.index('e') != 1:
                    if res1 == l - 1 - pme - pm - te:
                        return True
        return False

l = " 5e+123"
s = Solution()
print (s.isNumber(l))