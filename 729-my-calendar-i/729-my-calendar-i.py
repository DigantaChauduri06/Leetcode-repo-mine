class MyCalendar:
    
    def __init__(self):
        self.slots = []

    def book(self, start: int, end: int) -> bool:
        for st, ed in self.slots:
            if (start >= st and start < ed or
               end > st and end <= ed or
               start <= st and start < ed and ed > start and ed <= end):
                # print(start,end,[st,ed])
                return False
        self.slots.append([start, end])
        # print(self.slots)
        return True
                

"""
[19,30],[13,32]

"""
        
# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)