// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n){
        pair<double,int> bag[n];
        for(int i=0;i<n;i++){
            bag[i] = {(double)arr[i].value/arr[i].weight,arr[i].weight};
        }
        sort(bag,bag+n);
        reverse(bag,bag+n);
        double sum = 0;
        for(int i=0;i<n;i++){
            if(W <= 0 && i == n){
                break;
            }
            else if(W > bag[i].second){
                sum += (double)(bag[i].first*bag[i].second);
                W -= bag[i].second;
            }else if( W == bag[i].second){
                W -= bag[i].second;
                sum += (double)(bag[i].first*bag[i].second);
                break;
            }else if(W < bag[i].second){
                sum += (double)(bag[i].first*W);
                break;
            }
        }
        return sum;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends