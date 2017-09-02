'''
Given a List of words, return the words that can be typed using letters
of alphabet on only one row's of American keyboard
'''
class Solution(object):
    def findWords(self, words):
        out_words = []
        str1 = ['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p']
        str2 = ['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l']
        str3 = ['z', 'x', 'c', 'v', 'b', 'n', 'm']
        for word in words:
            res1, res2, res3 = 0, 0, 0
            for i in word:
                if i.lower() in str1:
                    res1 += 1
                if i.lower() in str2:
                    res2 += 1
                if i.lower() in str3:
                    res3 += 1
            if res1 == len(word) or res2 == len(word) or res3 == len(word):
                out_words += word.split(' ')
        return out_words

l = ["Hello", "Alaska", "Dad", "Peace"]
s = Solution()
print (s.findWords(l))