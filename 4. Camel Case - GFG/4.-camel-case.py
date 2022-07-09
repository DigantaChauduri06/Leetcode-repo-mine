#User function Template for python3

class Solution:
    
    #Function to print all words in the CamelCase dictionary 
    #that matches with a given pattern.
    def findAllWords(self, dict,pattern):
            m={}
            d={}
            for i in dict:
                code=""
                for j in i:
                    if ord(j)>=65 and ord(j)<=90:
                        code+=j
                        if code in d.keys():
                            d[code].append(i)
                        else:
                            d[code]=[i]
                m[i]=code
            if pattern not in d.keys():
                print("No match found",end="")
            else:
                for i in sorted(d[pattern],key=lambda x:(m[x],x)):
                    print(i,end=" ")
        

#{ 
#  Driver Code Starts
#Initial Template for Python 3

#contributed by RavinderSinghPB
if __name__ == '__main__': 
    t=int(input())
    for tcs in range(t):
        n=int(input())
        arr=input().strip().split()
        pattern=input()
        Solution().findAllWords(arr,pattern)
        print()
# } Driver Code Ends