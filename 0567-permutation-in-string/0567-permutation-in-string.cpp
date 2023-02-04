class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int> mpp;
        for (auto &s : s1) {
            mpp[s]++;
        }
        for (int i = 0;i <= s2.size() - s1.size();i++) {
                string sub = s2.substr(i, s1.size());
                // cout << sub << endl;
                unordered_map<char, int> map2;
                bool flag = false;
                // if  (sub.size() != s1.size()) continue;
                for (int k = 0;k < sub.size();k++) {
                    map2[sub[k]]++;
                }
                if (mpp == map2) return true; 
        }
        return false;
    }
};