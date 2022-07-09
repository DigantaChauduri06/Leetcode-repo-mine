#User function Template for python3


#Function to modify the matrix such that if a matrix cell matrix[i][j]
#is 1 then all the cells in its ith row and jth column will become 1.

def booleanMatrix(arr):
   # code here 
   row=set()
   col=set()
   n=len(arr)
   m=len(arr[0])
   for i in range(n):
       for j in range(m):
           if arr[i][j]==1:
               row.add(i)
               col.add(j)
   for i in range(n):
       for j in range(m):
           if i in row:
               arr[i][j]=1
           if j in col:
               arr[i][j]=1
   return arr

#{ 
#  Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        r,c = map(int, input().strip().split())
        matrix = []
        for i in range(r):
            line = [int(x) for x in input().strip().split()]
            matrix.append(line)
        booleanMatrix(matrix)
        for i in range(r):
            for j in range(c):
                print(matrix[i][j], end=' ')
            print()


# } Driver Code Ends