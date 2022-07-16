class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res,tmp = [],[]
        def restore(i, dots = 3):
            if i == len(s):
                # print(tmp, dots)
                if dots == -1:
                    res.append(".".join(tmp))
                return
            
            if i < len(s):
                num = (s[i:i+1])
                tmp.append(str(num))
                restore(i+1, dots-1)
                tmp.pop()
            if i < len(s) - 1:
                num = (s[i:i+2])
                if num[0] == '0':
                    return
                tmp.append(str(num))
                restore(i+2, dots-1)
                tmp.pop()
            if i < len(s) - 2 and int(s[i:i+3]) < 256:
                num = (s[i:i+3])
                if num[0] == '0':
                    return
                tmp.append(str(num))
                restore(i+3, dots - 1)
                tmp.pop()
                
        
        restore(0)
        return res
        
"""
25525511135


255.255.111.35

255.255.11.135



101023

101.0.23
1.0.10.23
10.10.2.3
1.0.102.3
"""