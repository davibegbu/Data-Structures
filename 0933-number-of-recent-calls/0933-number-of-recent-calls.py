class RecentCounter:

    def __init__(self):
        self.Request = []

    def ping(self, t: int) -> int:
        self.Request.append(t)
        while self.Request[0] < t - 3000:
            self.Request.pop(0)  
        return len(self.Request)
        
        
        


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)