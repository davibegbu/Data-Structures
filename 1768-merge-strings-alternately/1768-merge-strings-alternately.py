class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        wordLength = min(len(word1), len(word2))
        merged = []

        for i in range(wordLength):
            merged.append(word1[i])
            merged.append(word2[i])

        merged.append(word1[wordLength:])
        merged.append(word2[wordLength:])
    
        return ''.join(merged)