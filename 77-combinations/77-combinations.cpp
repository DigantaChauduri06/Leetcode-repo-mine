class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        //vector<int> nums;
        // for (int i = 1;i <= n;i++) {
        //     nums.push_back(i);
        // }
        vector<int> temp;
        fun(ans, temp,0, k, n+1);
        return ans;
    }
private:
    void fun(vector<vector<int>> &ans, vector<int> &temp,int i, int k, int n) {
        if (i== (n-1)) {
            if (size(temp) == k) {
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(i+1);
        fun(ans, temp, i+1, k, n);
        temp.pop_back();
        fun(ans, temp, i+1, k, n);
    }
};