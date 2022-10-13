#User function Template for python3

class Solution:
    
    #Function to check whether there is a subarray present with 0-sum or not.
    def subArrayExists(self,arr,n):
        ##Your code here
        #Return true or false
        mpp = set()
        sm = 0
        for i,num in enumerate(arr):
            sm += num
            # print(sm, end=" ")
            if sm == 0:
                return True
            if sm in mpp:
                # print(num,sm)
                return True
            # if i == len(arr) - 1 and sm :
            # print(sm, end = " ")
            mpp.add(sm)
        # print(mpp)
        if sm == 0:
            return True
        return False


#{ 
 # Driver Code Starts
#Initial Template for Python 3



def main():
    T=int(input())
    while(T>0):
        
        n=int(input())
        arr=[int(x) for x in input().strip().split()]
        if(Solution().subArrayExists(arr,n)):
            print("Yes")
        else:
            print("No")
        
        
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends