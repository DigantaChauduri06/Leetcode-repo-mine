class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& I, vector<int>& NI) {
        
        I.push_back(NI);
        sort(begin(I), end(I));
        return mergeIntervals(I, NI);;
    }
private:
    vector<vector<int>> mergeIntervals(vector<vector<int>> &I,vector<int>& NI) {
        vector<vector<int>> ans;
        ans.push_back(I[0]);
        for (int i = 1;i < size(I);i++) {
            if (ans.back()[1] >= I[i][0]) {
                ans.back()[1] = max(ans.back()[1], I[i][1]);
            }
            else {
                ans.push_back(I[i]);
            }
        }
        return ans;
    }
};

/*
    [[1,2],[3,5],[6,7],[8,10],[12,16]]
    [4,8]

*/