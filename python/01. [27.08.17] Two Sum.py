'''
Given an array of integers, return indices of the two numbers such that they 
add up to a specific target. You may assume that each input would have exactly 
one solution, and you may not use the same element twice.
'''
import copy
def twoSum(nums, target):
    snums = copy.copy(nums)
    snums.sort()
    r = [0,0]
    for i in snums:
        a = 0
        for j in snums[a:]:
            b = 1
            if i + j == target:
                r = [i,j]
                break
            b += 1
        if r[0] != 0:
            break
        a += 1
    res = []
    ind = nums.index(r[0])
    res.append(ind)
    nums [ind] = nums [ind] + 1
    ind = nums.index(r[1])
    res.append(ind)
    res.sort()
    return res

l = [0,4,3,0]
ch = 0
print (twoSum(l, ch))