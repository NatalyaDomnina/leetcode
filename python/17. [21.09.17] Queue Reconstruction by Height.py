'''
Suppose you have a random list of people standing in a queue. 
Each person is described by a pair of integers (h, k), where h 
is the height of the person and k is the number of people in 
front of this person who have a height greater than or equal 
to h. Write an algorithm to reconstruct the queue.
'''
class Solution(object):
    def reconstructQueue2(self, people):
        if len(people) < 2:
            return people

        res = []
        a = set()

        people.sort(reverse = True)

        for i in range(len(people)):
            if people[i][0] != people[0][0]:
                a.add(people[i][0])

        i = 0
        while people[i][0] == people[0][0]:
            res.append(people[i])
            i += 1
        res.sort()

        a = list(a)
        a.sort(reverse = True)

        for i in a:
            tmp = []
            for j in range(len(people)):
                if people[j][0] == i:
                    tmp.append(people[j])
            tmp.sort()
            for j in range(len(tmp)):
                res.insert(tmp[j][1], tmp[j])

        return res

l = [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

s = Solution()
print(s.reconstructQueue2(l))