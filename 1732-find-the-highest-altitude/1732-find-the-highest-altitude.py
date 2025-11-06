class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        altitude = 0 
        altitudeList = [0]
        for i in range(len(gain)):
            altitude += gain[i]
            altitudeList.append(altitude)
        
        return max(altitudeList)