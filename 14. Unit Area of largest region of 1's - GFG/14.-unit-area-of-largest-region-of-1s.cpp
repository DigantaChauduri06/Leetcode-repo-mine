// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int n, m;
    const int dx[8] = {0,  0, 1, -1,  1, -1, -1,  1};
    const int dy[8] = {1, -1, 0,  0,  1, -1,  1, -1};
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(vector<vector<int>> &grid, int i, int j, int &c){
        if(!grid[i][j])
            return;
        c += 1;
        grid[i][j] = 0;
        for(int k=0; k<8; k++){
            int x = i+dx[k];
            int y = j+dy[k];
            if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y]){
                dfs(grid, x, y, c);
            }
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]){
                    int c = 0;
                    dfs(grid, i, j, c);
                    ans = max(ans, c);
                }
            }
        }
        return ans;
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
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends