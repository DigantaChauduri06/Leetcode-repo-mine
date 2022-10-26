class LUPrefix:
    def __init__(self, n: int):
        self.last = []
        self.uvideo = set()
    def upload(self, video: int) -> None:
        self.uvideo.add(video)

    def longest(self) -> int:
        if not self.uvideo or 1 not in self.uvideo:
            return 0
        i = 1 if not self.last else self.last[-1]
        while i in self.uvideo:
            i+=1
        self.last.append(i-1)
        return i-1
        


# Your LUPrefix object will be instantiated and called as such:
# obj = LUPrefix(n)
# obj.upload(video)
# param_2 = obj.longest()