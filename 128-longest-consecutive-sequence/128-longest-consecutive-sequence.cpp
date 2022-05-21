class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        int mx = 0;
        for (auto num : nums) {
            int cur = 0;
            if (st.find(num-1) == st.end()) {
                while (st.find(num) != st.end()) {
                    cur++;
                    num++;
                }
                
            }
            mx = max(mx, cur);
        }
        return mx;
    }
};