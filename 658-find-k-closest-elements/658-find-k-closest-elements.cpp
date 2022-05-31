class Solution {
typedef pair<int,int> pii;
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    
        auto comp = [](pii &a, pii &b) {
            return a.second <= b.second;
        };
        priority_queue<pii, vector<pii>, decltype(comp)> pq(comp);
        for (int i = 0;i < arr.size();i++) {
            int diff = abs(arr[i] - x);
            pq.push({arr[i], diff});
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while (pq.size() != 0) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};