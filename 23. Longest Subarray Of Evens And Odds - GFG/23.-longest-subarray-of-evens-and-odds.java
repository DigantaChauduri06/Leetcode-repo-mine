// { Driver Code Starts
//Initial Template for Java


import java.util.*;
import java.io.*;
import java.lang.*;

class Driver
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        
        //testcases
        int t = Integer.parseInt(read.readLine());
        
        while(t-- > 0)
        {
            //size of array
            int n = Integer.parseInt(read.readLine());
            String str[] = read.readLine().trim().split(" ");
            int arr[] = new int[n];
            
            //inserting elements in the array
            for(int i = 0; i < n; i++)
                arr[i] = Integer.parseInt(str[i]);
            //calling function    
            System.out.println(new Solution().maxEvenOdd(arr, n));
            
        }
    }
}   // } Driver Code Ends


//User function Template for Java

// User class to complete  
class Solution
{
  
   public static int maxEvenOdd(int arr[], int n)
   {
       int maxC=1,curr_Length=1;
       
       for(int i=1;i<n;i++)
       {
           if((arr[i]%2==0 && arr[i-1]%2!=0)||(arr[i]%2!=0 && arr[i-1]%2==0))
           {
               curr_Length++;
               maxC=Math.max(maxC,curr_Length);
           }
           else{
               curr_Length=1;
           }
       }
       return maxC;
   }
}