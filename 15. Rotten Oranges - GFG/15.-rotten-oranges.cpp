// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    int ROW, COL;
    int _time = 0;
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        int fresh = 0;
        ROW = grid.size(); COL = grid[0].size();
        for (int i = 0;i < ROW;i++) {
            for (int j = 0;j < COL;j++) {
                if (grid[i][j] == 2) {
                    q.push({i,j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        while (q.size() != 0 && fresh) {
            int size = q.size();
            while (size--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                if (isValid(grid, r+1, c)) {
                    grid[r+1][c] = 2;
                    q.push({r+1, c});
                    fresh--;
                }
                if (isValid(grid, r, c+1)) {
                    grid[r][c+1] = 2;
                    q.push({r, c+1});
                    fresh--;
                }
                if (isValid(grid, r, c-1)) {
                    grid[r][c-1] = 2;
                    q.push({r, c-1});
                    fresh--;
                }
                if (isValid(grid, r-1, c)) {
                    grid[r-1][c] = 2;
                    q.push({r-1, c});
                    fresh--;
                }
            }
            _time++;
        }
        return fresh == 0 ? _time : -1;
    }
private:
bool isValid(vector<vector<int>> &grid, int r, int c) {
    return (r >= 0 
    && c >= 0
    && r < ROW
    && c < COL
    && grid[r][c] == 1);
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends