class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& I) {
        sort(begin(I), end(I));
        auto last = I[0][1];
        int cnt = 0;
        for (int i = 1;i < size(I);i++) {
            if (last > I[i][0]) {
                cnt++;
                last = min(last, I[i][1]);
            }
            else {
                last = I[i][1];
            }
        }
        return cnt;
    }
};