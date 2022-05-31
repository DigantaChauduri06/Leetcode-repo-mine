class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (auto &n : nums) {
            mpp[n]++;
        }
        vector<pair<int, int>> vc;
        for(auto &m : mpp) {
            vc.push_back({m.second, m.first});
        }
        sort(begin(vc), end(vc), comp);
        vector<int> ans;
        for (int i = 0;i < vc.size();i++) {
            int times = vc[i].first;
            int ori = vc[i].second;
            for (int j = 0;j < times;j++) {
                ans.push_back(ori);
            }
        }
        return ans;
    }
            // cout << vc[i].second << " " << vc[i].first << endl;
private:
    static bool comp(pair<int, int> &a, pair<int, int> &b) {
        if (a.first != b.first) {
            return a.first <= b.first;
        }
        else return a.second >= b.second;
    }
};