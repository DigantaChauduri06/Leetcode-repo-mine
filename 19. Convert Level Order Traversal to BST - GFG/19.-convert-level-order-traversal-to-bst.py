#User function Template for python3


#Function to construct the BST from its given level order traversal.

 

 


class Tree:
   def createnode(self, data):
       return Node(data)
   
   def insert(self, node, data):
       if node is None:
           return self.createnode(data)
       else:
           if data>node.data:
               node.right = self.insert(node.right, data)
           else:
               node.left = self.insert(node.left, data)
           return node


#Function to construct the BST from its given level order traversal.
def constructBst(arr,n):
   bst = Tree()
   root = None
   root = bst.insert(root, arr[0])
   for i in range(1,n):
       root = bst.insert(root, arr[i])
   return root

#{ 
#  Driver Code Starts
#Initial Template for Python 3
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None

    
def preOrder(root):
    if root is None:
        return 
    print(root.data,end=" ")
    preOrder(root.left)
    preOrder(root.right)
    


def main():
    testcases=int(input())
    while(testcases>0):
        root=None
        sizeOfArray=int(input())
        arr=[int(x) for x in input().strip().split()]
      
        root=constructBst(arr,sizeOfArray)
        
        preOrder(root)
        print()
       
        testcases-=1

if __name__=="__main__":
    main()
# } Driver Code Ends