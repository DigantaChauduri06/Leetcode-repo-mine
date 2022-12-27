//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) { 
        // your code here
        int mx = 0;
        for (int i = 0;i < n;i++) {
            mx = max(arr[i].dead, mx);
        }
        // cout << mx << endl;
        vector<int> deadline(mx, -1);
        sort(arr, arr+n, comp);
        int sm = 0, cnt = 0;
        // for (int i = 0;i < n;i++) {
        //     cout << arr[i].profit << " ";
        // }
        // cout << endl;
        for (int i = 0;i < n;i++) {
            int dead = arr[i].dead - 1, profit = arr[i].profit;
            if (canSet(deadline, dead)) {
                cnt+=1;
                // cout << profit << endl;
                sm+=profit;
            }
        }
        return {cnt, sm};
        
        
    }
    private:
    int canSet(vector<int> &deadline, int dead) {
        for (int i = dead;i >= 0;i-=1) {
            if (deadline[i] == -1) {
                deadline[i] = 1;
                return true;
            }
        }
        return false;
    }
    static bool comp(Job &a, Job &b) {return a.profit > b.profit;}
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends