
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        n = 0  
    
        for i in range(len(t)):
            if n == len(s):
                break
            
            if s[n] == t[i]:
                n += 1

        return n == len(s)