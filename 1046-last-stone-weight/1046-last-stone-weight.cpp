class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size() == 0) return 0;
        if (stones.size() == 1) return stones[0];
        priority_queue<int> pq;
        for (auto &s : stones) {
            pq.push(s);
        }
        while (pq.size() > 1) {
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            int dif = top1 - top2;
            if (dif == 0) continue;
            pq.push(dif);
        }
        return pq.size() != 0 ? pq.top() : 0;
    }
};