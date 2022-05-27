class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        int n = s.length();
        fun(s,ans, part,0);
        return ans;
    }
private:
    void fun(string &s, vector<vector<string>> &ans, vector<string> &part, int i) {
        if (i >= size(s)) {
            ans.push_back(part);
            return;
        }
        // genrate all the possible substrings
        for (int j = i;j < size(s);j++) {
            if (isPalin(s, i, j)) {
                part.push_back(s.substr(i, (j-i +1)));
                fun(s, ans, part, j+1);
                part.pop_back();
            }
        }
    } 
    bool isPalin(string &s, int low, int high) {
        while (low <= high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
};