class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        unordered_map<char, int> mpp;
        for (auto &s : s1) {
            mpp[s]++;
        }
        for (int i = 0;i <= s2.size() - s1.size();i++) {
                // string sub = s2.substr(i, s1.size());
                unordered_map<char, int> map2;
                bool flag = false;
                for (int k = i;k < i+s1.size();k++) {
                    map2[s2[k]]++;
                }
                if (mpp == map2) return true; 
        }
        return false;
    }
};