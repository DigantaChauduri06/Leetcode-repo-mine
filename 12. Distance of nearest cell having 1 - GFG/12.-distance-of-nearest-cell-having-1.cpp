// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    int ROW, COL;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, 1, -1, 0};
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    ROW = grid.size(), COL = grid[0].size();
	    queue<pair<int,int>> q;
	    vector<vector<bool>> state(ROW, vector<bool>(COL, false));
	    for (int i = 0;i < ROW;i++) {
	        for (int j = 0;j < COL;j++) {
	            if (grid[i][j] == 1) {
	                grid[i][j] = 0;
	                q.push({i,j});
	                state[i][j] = 1;
	            }
	        }
	    }
	    while (!q.empty()) {
	        int size = q.size();
	        while (size--) {
	            int row = q.front().first;
	            int col = q.front().second;
    	        q.pop();
	            int dis = grid[row][col];
	            for (int i = 0;i < 4;i++) {
	                int r = row + dx[i];
	                int c = col + dy[i];
	                if (inRange(state, r, c)) {
	                    state[r][c] = true;
	                    grid[r][c] = 1 + grid[row][col];
	                    q.push({r, c});
	                }
	            }
	        }
	    }
	    return grid;
	}
private:
    bool inRange(vector<vector<bool>> &state, int r, int c) {
        return r >= 0 
            && c >= 0
            && r < ROW
            && c < COL
            && !state[r][c];
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends