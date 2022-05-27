class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        if (nums.size() == 1) {
            if (nums[0] == "0") {
                return  "1";
            } else return "0";
        }
        vector<pair<int, int>> pr;
        int n = nums.size();
        int cur = 0;
        for (int i = 1;i <= (n-1);i++) {
            int lb = cur;
            int ub = (1 << (i+1))-1;
            pr.push_back({lb,ub});
            cur = ub+1;
        }
        auto range = pr[n - 2];
        int lb = range.first, ub = range.second;
        //cout << range.first << " " << range.second << endl;
        sort(begin(nums), end(nums));
        // for (auto &s : nums) {cout << s << " ";}
        //cout << decimalToBin(1, n) << endl;
        int k = 0;
        for (int i = 0;i <= ub && k < nums.size();i++) {
            string str = decimalToBin(i, n);
            //cout << i << " : " << str << endl;
            if (str != nums[k]) return str;
            k++;
        }
        return decimalToBin(ub, n);
    }
private:
    string decimalToBin(int n, int size) {
        string str = "";
        if (n == 0) {
            for (int i = 0;i < size;i++) {
                str += "0";
            }
            return str;
        }
        for (int i = 31; i >= 0;i--) {
            int lb = (n >> i) & 1;
            if (lb&1) {
                str.push_back('1');
            } else {
                str.push_back('0');
            }
            // n = n >> 1;
        }
        //reverse(begin(str), end(str));
        // cout << n << " : " << str << endl;
        return str.substr(str.size() - size, size);
    }
};