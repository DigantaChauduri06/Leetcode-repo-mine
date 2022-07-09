// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
void heapify(int arr[], int n, int i)  
    {
        if(n==1)
            return;
        int lc = (i<<1)|1 ,rc=lc+1,largest=i;
        if(lc<n && arr[lc]>arr[largest])
            largest=lc;
        if(rc<n && arr[rc]>arr[largest])
            largest=rc;
        // means child was larger than parent, so parent child swapped, now heapify done on new child
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }

    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=(n>>1)-1;i>=0;i--)
            heapify(arr,n,i);
    }

    
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr,n);
        int size=n;
        while(--size){
            swap(arr[0],arr[size]);
            heapify(arr,size,0);
        }
    }
};




// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends