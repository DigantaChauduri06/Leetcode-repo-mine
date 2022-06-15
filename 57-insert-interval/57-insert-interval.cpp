class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& I, vector<int>& NI) {
        int i = 0;
        int n = size(I);
        vector<vector<int>> result;
        while (i < n && NI[0] > I[i][1]) {
            result.push_back(I[i]);
            i++;
        }
        while (i < n && NI[1] >= I[i][0]) {
            NI[0] = min(I[i][0], NI[0]);
            NI[1] = max(I[i][1], NI[1]);
            i++;
        }
        result.push_back(NI);
        while (i < n) {
            result.push_back(I[i]);
            i++;
        }
        return result;
        
    }
};
/*
    3 steps:

    1. push all the intervals before the starting of New                    Intervals
    2. merge the new Interval
    3. add all the remaining intervals in the result
*/
/*
    [[1,2],[3,5],[6,7],[8,10],[12,16]]
    [19, 200]

*/