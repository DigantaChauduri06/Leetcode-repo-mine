class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& cand, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(begin(cand), end(cand));
        fun(cand, tar, ans, temp ,0);
        return ans;
    }
private:
    void fun(vector<int>& cand, int k,vector<vector<int>> &ans, vector<int> &temp, int j) {
        if (k == 0) {
            ans.push_back(temp);
            return;
        }
        if (k < 0) return;
        int prev = -1;
        for (int i = j;i < cand.size();i++) {
            if (cand[i] == prev) continue;
            temp.push_back(cand[i]);
            fun(cand, k - cand[i], ans, temp, i+1);
            temp.pop_back();
            prev = cand[i];
        }
       
    }
};