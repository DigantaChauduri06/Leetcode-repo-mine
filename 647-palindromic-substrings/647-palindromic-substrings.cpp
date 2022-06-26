class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        for (int i = 0;i < s.length();i++) {
            int odd = getPalin(s, i, i);
            int even = getPalin(s, i, i+1);
            cnt += even + odd;
        }
        return cnt;
    }
private:
    int getPalin(string &s, int si, int ei) {
        int cnt = 0;
        while (si >= 0 && ei < s.length() && s[si] == s[ei]) {
            cnt++;
            si--, ei++;
        }
        return cnt;
    }
};
// abbcabc
/*
a
aa
aaa
aa
a


*/