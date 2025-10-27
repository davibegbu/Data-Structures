class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = 'aeiouAEIOU'
        vowel_chars = []
        for i in range(len(s)):
            if s[i].lower() in vowels:
                vowel_chars.append(s[i])
        vowel_chars.reverse()

        result = []
        vowel_iter = iter(vowel_chars)
        for char in s:
            if char in vowels:
                result.append(next(vowel_iter))
            else:
                result.append(char)

        return ''.join(result)



