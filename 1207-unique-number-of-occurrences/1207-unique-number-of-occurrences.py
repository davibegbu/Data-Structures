class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        counts = {}

        for i in arr:
            if i in counts: 
                counts[i] += 1
            else:
                counts[i] = 1

        occurences = list(counts.values())

        if len(occurences) == len(set(occurences)):
            return True
        else: 
            return False
        

