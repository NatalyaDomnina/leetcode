'''
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, 
judge if this robot makes a circle, which means it moves back to the original 
place. The move sequence is represented by a string. And each move is represent 
by a character. The valid robot moves are R (Right), L (Left), U (Up) and 
D (down). The output should be true or false representing whether the robot 
makes a circle.
'''
class Solution:
    def judgeCircle(self, moves):
        if moves.count("U") == moves.count("D"):
            if moves.count("L") == moves.count("R"):
                return True
            else:
               return False
        else:
            return False
        
        
mov_str = "UD"
obj = Solution()
obj.judgeCircle(mov_str)