class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        n = len(nums)
        maxAvg = float('-inf')

        # iterate through all possible subarrays of length k
        for i in range(n - k + 1):
            window_sum = 0
            # sum up the elements in the current window
            for j in range(i, i + k):
                window_sum += nums[j]
            # calculate average
            newMaxAvg = window_sum / k
            # update maximum average
            if newMaxAvg > maxAvg:
                maxAvg = newMaxAvg

        return maxAvg
