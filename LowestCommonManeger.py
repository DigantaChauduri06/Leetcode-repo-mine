def helper(manager, r1, r2):
    numOfCommon = 0
    for dir in manager.directReports:
        orgInfo = helper(dir, r1, r2)
        if orgInfo.lowestCommonManager is not None:
            return orgInfo
        numOfCommon += orgInfo.numberOfImportantPerson
    if manager == r1 or manager == r2:
        numOfCommon += 1
    lowest = None
    if numOfCommon == 2:
        lowest = manager
    return OrgInfo(lowest, numOfCommon)
        
    


def getLowestCommonManager(topManager, reportOne, reportTwo):
    # Write your code here.
    return helper(topManager, reportOne, reportTwo).lowestCommonManager
        


class OrgInfo:
    def __init__(self, lowestCommonManager, numberOfImportantPerson):
        self.lowestCommonManager = lowestCommonManager
        self.numberOfImportantPerson = numberOfImportantPerson

# This is an input class. Do not edit.
class OrgChart:
    def __init__(self, name):
        self.name = name
        self.directReports = []
