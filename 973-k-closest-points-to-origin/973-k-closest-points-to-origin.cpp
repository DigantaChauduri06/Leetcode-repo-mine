class Solution {
    typedef pair<float, vector<int>> prii;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {                                                       
        auto comp = [](prii &a, prii &b) {
            // max-heap
            return a.first <= b.first;
        };
        priority_queue<prii,vector<prii>, decltype(comp)> pq(comp);
        for (int i = 0;i < p.size();i++) {
            long long a = p[i][0] * p[i][0];
            long long b = p[i][1] * p[i][1];
            float diff = sqrt((a+b));
            pq.push({diff, p[i]});
            if (pq.size() > (k)) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};