'''
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single 
digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the 
number 0 itself.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
'''
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, value = None, next = None):
        self.value = value
        self.next = next
    def __str__(self):
        return (str(self.value)) 
        
class LinkedList(object):
    def __init__(self):
        self.first = None
        self.last = None
        self.length = 0
    def __str__(self):
        if self.first != None:
            current = self.first
            out = 'LinkedList [ ' + str(current.value) + ' '
            while current.next != None:
                current = current.next
                out += str(current.value) + ' '
            return out + ']'
            return 'LinkedList []'
    def clear(self):
        self.__init__()
    def add(self, x):
        self.length += 1
        if self.first == None:
            self.last = self.first = ListNode(x, None)
        else:
            self.last.next = self.last = ListNode(x, None)

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        l3 = LinkedList()
        current_l1 = l1.first
        current_l2 = l2.first
        for i in range(l1.length):
            if (current_l1.value + current_l2.value) // 10 != 0:
                l3.add((current_l1.value + current_l2.value) % 10) 
                current_l2.next.value += (current_l1.value + current_l2.value) // 10
            else:
                l3.add(current_l1.value + current_l2.value)
            
            if current_l1.next != None:
                    current_l1 = current_l1.next
                    current_l2 = current_l2.next
        return l3

l1 = LinkedList()
l1.add(9)
l1.add(2)
l1.add(4)

print (l1)

l2 = LinkedList()
l2.add(2)
l2.add(3)
l2.add(5)

print (l2)

s = Solution()
print (s.addTwoNumbers(l1, l2))