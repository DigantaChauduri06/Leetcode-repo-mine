// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    int ROW, COL;
public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        //code here
        ROW = grid.size(), COL = grid[0].size();
        for (int i = 0;i < ROW;i++) {
            for (int j = 0;j < COL;j++) {
                if (grid[i][j] == 1) {
                    if (dfs(grid, i, j))
                        return true;
                    return false;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 
            || j < 0 
            || i >= ROW 
            || j >= COL 
            || grid[i][j] == 0) 
                return false;
        if (grid[i][j] == 2) 
            return true;
        grid[i][j] = 0;
        // 4 dirs
        return (dfs(grid, i+1, j) 
            || dfs(grid, i, j+1) 
            || dfs(grid, i-1, j)
            || dfs(grid, i, j-1));
    }
    
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}  // } Driver Code Ends