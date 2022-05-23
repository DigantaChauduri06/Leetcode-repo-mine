class Solution {
public:
 vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {                                                       
        auto comp = [](pair<float, vector<int>> &a, pair<float, vector<int>> &b) {
            return a.first < b.first;
        };
        // priority_queue<pair<int, vector<int>>,vector<int>, decltype(comp)> pq(comp);
        vector<pair<float, vector<int>>> arr;
        for (int i = 0;i < p.size();i++) {
            long long a = p[i][0] * p[i][0];
            long long b = p[i][1] * p[i][1];
            float diff = sqrt((a+b));
            pair<float, vector<int>> pr = {diff, p[i]};
            arr.push_back(pr);
        }
        vector<vector<int>> ans;
        sort(begin(arr), end(arr), comp);
        for (int i = 0;i < k;i++) {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};