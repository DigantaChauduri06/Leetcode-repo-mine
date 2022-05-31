class Solution {
typedef pair<int, int> pii;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (auto &n : nums) {
            mpp[n]++;
        }
        auto comp = [](pii &a, pii &b) {
          return a.second >= b.second;  
        };
        priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);
        for (auto &m : mpp) {
            pq.push({m.first, m.second});
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};