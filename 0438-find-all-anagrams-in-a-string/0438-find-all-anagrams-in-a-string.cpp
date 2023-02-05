class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int sn = size(s), sp = size(p);
        if (sn < sp) return ans;
        unordered_map<char, int> v1, v2;
        int i = 0;
        for (i;i < sp;i++) {
            v1[s[i]]++;
            v2[p[i]]++;
        }
        int j = 0;
        while (i < sn) {
            if (v1 == v2) ans.push_back(j);
            v1[s[i++]]++;
            v1[s[j]]--;
            if (v1[s[j]] == 0) 
                v1.erase(s[j]);
            j++;
        }
        if (v1 == v2) {
            ans.push_back(j);
        }
        return ans;
    }
};