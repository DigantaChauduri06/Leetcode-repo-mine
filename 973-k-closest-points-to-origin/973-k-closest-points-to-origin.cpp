class Solution {
typedef pair<int, vector<int>> pvi;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](pvi &a, pvi &b) {
          return a.first <= b.first;  
        };
        vector<vector<int>> ans;
        priority_queue<pvi, vector<pvi>, decltype(comp)> pq(comp);
        for (int i = 0;i < points.size();i++) {
            int a = points[i][0];
            int b = points[i][1];
            int dis = a*a + b*b;
            pq.push({dis, points[i]});
            if (pq.size() > k) pq.pop();
        }
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};