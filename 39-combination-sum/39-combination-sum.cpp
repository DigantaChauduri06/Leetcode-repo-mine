class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(begin(cand),end(cand));
        fun(cand, ans, temp, tar, 0);
        return ans;
    }
private:
    void fun(vector<int> &cand, vector<vector<int>> &ans, vector<int> &temp, int tar, int i) {
        if (i >= cand.size()) {
            if (tar == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if (tar == 0) {
            ans.push_back(temp);
            return;
        }
        if ((tar - cand[i]) >= 0) {
            temp.push_back(cand[i]);
            fun(cand, ans, temp, tar - cand[i], i);
            temp.pop_back();
        }
        fun(cand, ans, temp, tar, i+1);
    }
};