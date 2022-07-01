class Solution:
    def maximumUnits(self, boxes: List[List[int]], mxTruck: int) -> int:
        boxes.sort(key = lambda x: x[1], reverse = True)
        ans, cur = 0, 0
        for box in boxes:
            trucks, ele = box
            if ((cur + trucks) > mxTruck):
                canTake = mxTruck - cur
                ans += (ele * canTake)
                break
            else:
                ans += (ele * trucks)
                cur += trucks
        return ans
# boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]

'''
[
    [1,3],[2,2],[3,1]
]


1 * 3 + 2 * 2 + 1 * 1 = 8


'''