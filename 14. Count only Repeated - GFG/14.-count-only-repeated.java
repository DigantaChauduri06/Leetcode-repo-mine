// { Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.awt.Point; 
import java.util.Arrays; 
import java.util.Vector; 
class GFG {
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		
		int t=sc.nextInt();
		
		while(t-->0)
		{
		    int n=sc.nextInt();
		    Integer arr[] = new Integer[n];
		    for(int i=0;i<n;i++)
		    arr[i]=sc.nextInt();
		    
		    Point p=new Solution().findRepeating(arr,n);
            
            System.out.println(p.x +" "+ p.y ); 
		    
		}
		
		
	}
}// } Driver Code Ends


//User function Template for Java

class Solution
{
   //Function to find repeated element and its frequency.
   public static Point findRepeating(Integer arr[],int n)
   {
       //Your code here
         HashMap<Integer,Integer>h=new  HashMap<Integer,Integer>();
      for(int i=0;i<n;i++)
      {
          if(h.containsKey(arr[i]))
          {
              h.put(arr[i],h.get(arr[i])+1);
          }
          else
          {
              h.put(arr[i],1);
          }
      }
      for(int i=0;i<n;i++){
          if(h.get(arr[i])>1)
      {
          return new Point(arr[i],h.get(arr[i]));
      }
  }
  
  return new Point(-1,-1);
   }  
};