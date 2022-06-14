// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    int ROW, COL;
    public:
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) {
        // Code here
        int cnt = 0;
        ROW = grid.size(), COL = grid[0].size();
        for (int i = 0;i < ROW;i++) {
            for (int j = 0;j < COL;j++) {
                if (grid[i][j] == 'X') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
private:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= ROW || j >= COL || grid[i][j] != 'X') 
            return;
        grid[i][j] = 'U';
        dfs(grid, i+1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i-1, j);
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends