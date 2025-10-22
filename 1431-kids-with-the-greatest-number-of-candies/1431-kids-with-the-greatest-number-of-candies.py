class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        results = []
        maxCandies = max(candies)

        for i in range(len(candies)):
            if candies[i] + extraCandies >= maxCandies:
                results.append(True)
            else:
                results.append(False)
        return results
