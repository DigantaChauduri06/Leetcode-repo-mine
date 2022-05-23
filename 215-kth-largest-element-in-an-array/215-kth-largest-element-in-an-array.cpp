class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto comp = [](int &a, int &b) {
            // min-heap
            return a >= b;
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (auto &num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};